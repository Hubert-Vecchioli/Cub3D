/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 04:55:28 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 16:25:12 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_get_wall_direction_hit(t_game *game)
{
	if (game->ray->side == 0)
		game->ray->perpwalldist = game->ray->distance_to_first_x - game->ray->distance_to_next_x;
	else if (game->ray->side == 1)
		game->ray->perpwalldist = game->ray->distance_to_first_y - game->ray->distance_to_next_y;
	if (game->ray->side == 0 && game->ray->stepx == 1)
		game->ray->side = 3;
	if (game->ray->side == 1 && game->ray->stepy == -1)
		game->ray->side = 2;
	if (game->ray->side == 0 || game->ray->side == 3)
		game->ray->wall_x = game->player->posy + game->ray->perpwalldist * game->ray->raydiry;
	else
		game->ray->wall_x = game->player->posx + game->ray->perpwalldist * game->ray->raydirx;
	game->ray->wall_x -= floor(game->ray->wall_x);
}

void	ft_init_line(t_game *game)
{
	game->line->lineheight = (int)(HEIGHT / game->ray->perpwalldist);
	game->line->drawstart = (-game->line->lineheight / 2 + HEIGHT / 2);
	if (game->line->drawstart < 0)
		game->line->drawstart = 0;
	game->line->drawend = (game->line->lineheight / 2 + HEIGHT / 2);
	if (game->line->drawend >= HEIGHT)
		game->line->drawend = HEIGHT - 1;
	game->line->y = game->line->drawend - game->line->drawstart;
	game->line->x = game->ray->x;
	game->line->pos_in_texture_x = (game->ray->wall_x * game->tex_size);
	game->line->span = game->tex_size;
	game->line->off = 0;
	if (game->ray->x == WIDTH / 2 && game->ray->hit == 2 && game->ray->perpwalldist < 1)
		game->ray->aiming_at_door = 1;
	if (game->line->y >= HEIGHT - 1)
	{
		game->line->span = (game->ray->perpwalldist * game->tex_size);
		game->line->off = (game->tex_size * 0.5) * (1 - game->ray->perpwalldist);
	}
}

void	ft_draw_wall_line(t_game *game)
{
	int	screen_row_id;

	screen_row_id = game->line->drawstart;
	while (screen_row_id < game->line->drawend)
	{
		game->line->pos_in_texture_y = ((((double)screen_row_id - (double)game->line->drawstart)
			/ ((double)game->line->drawend - (double)game->line->drawstart)) * (double)game->line->span + (double)game->line->off);
		if (BONUS && game->ray->hit == 2)
			game->line->tex_color = game->textures[4][game->line->pos_in_texture_x * game->tex_size + game->line->pos_in_texture_y];
		else 
			game->line->tex_color = game->textures[game->ray->side][game->line->pos_in_texture_x * game->tex_size + game->line->pos_in_texture_y];
		ft_color_single_pixel(game, game->ray->x, screen_row_id, game->line->tex_color);
		screen_row_id++;
	}
}
