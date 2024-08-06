/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebesnoin <ebesnoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:47:02 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 11:21:25 by ebesnoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_init_new_ray(t_game *game)
{
	game->ray->camerax = 2 * game->ray->x / (double)WIDTH - 1;
	game->ray->raydirx = game->player->direction_x
		+ game->player->user_screen_x * game->ray->camerax;
	game->ray->raydiry = game->player->direction_y
		+ game->player->user_screen_y * game->ray->camerax;
	game->ray->mapx = (int)game->player->posx;
	game->ray->mapy = (int)game->player->posy;
	if (game->ray->raydirx)
		game->ray->distance_to_next_x = fabs(1 / game->ray->raydirx);
	else
		game->ray->distance_to_next_x = 1 / 0.000001;
	if (game->ray->raydiry)
		game->ray->distance_to_next_y = fabs(1 / game->ray->raydiry);
	else
		game->ray->distance_to_next_y = 1 / 0.000001;
	game->ray->hit = 0;
}

static void	ft_init_new_ray_dists(t_game *game)
{
	if (game->ray->raydirx < 0)
	{
		game->ray->stepx = -1;
		game->ray->distance_to_first_x = (game->player->posx - game->ray->mapx) * game->ray->distance_to_next_x;
	}
	else
	{
		game->ray->stepx = 1;
		game->ray->distance_to_first_x = (game->ray->mapx + 1.0 - game->player->posx)
			* game->ray->distance_to_next_x;
	}
	if (game->ray->raydiry < 0)
	{
		game->ray->stepy = -1;
		game->ray->distance_to_first_y = (game->player->posy - game->ray->mapy) * game->ray->distance_to_next_y;
	}
	else
	{
		game->ray->stepy = 1;
		game->ray->distance_to_first_y = (game->ray->mapy + 1.0 - game->player->posy)
			* game->ray->distance_to_next_y;
	}
}

static void	ft_loop_ray_until_a_hit(t_game *game)
{
	while (game->ray->hit == 0)
	{
		if (game->ray->distance_to_first_x < game->ray->distance_to_first_y)
		{
			game->ray->distance_to_first_x += game->ray->distance_to_next_x;
			game->ray->mapx += game->ray->stepx;
			game->ray->side = 0;
		}
		else
		{
			game->ray->distance_to_first_y += game->ray->distance_to_next_y;
			game->ray->mapy += game->ray->stepy;
			game->ray->side = 1;
		}
		if (game->map[game->ray->mapx][game->ray->mapy] == '1')
			game->ray->hit = 1;
		if (BONUS)
		{
			if (game->map[game->ray->mapx][game->ray->mapy] == 'D')
			{
				game->ray->hit = 2;
				game->ray->door_pos_x = game->ray->mapx;
				game->ray->door_pos_y = game->ray->mapx;
			}
			if (game->map[game->ray->mapx][game->ray->mapy] == 'W' && game->ray->x == WIDTH /2) // modifcation de data --> map
			{
				if (game->ray->side == 0)
					game->ray->perpwalldist = (game->ray->distance_to_first_x - game->ray->distance_to_next_x);
				else if (game->ray->side == 1)
					game->ray->perpwalldist = (game->ray->distance_to_first_y - game->ray->distance_to_next_y);
				if (game->ray->perpwalldist < 1)
				{
					game->ray->aiming_at_open_door = 1;
					game->ray->door_pos_x = game->ray->mapx;
					game->ray->door_pos_y = game->ray->mapx;
				}
			}
		}
	}
}

static void	ft_draw_floor_and_ceiling(t_game *game)
{
	int	screen_col_id;
	int	screen_row_id;

	screen_row_id = 0;
	while (screen_row_id < WIDTH)
	{
		screen_col_id = 0;
		while (screen_col_id < HEIGHT)
		{
			if (screen_col_id <= HEIGHT / 2)
				ft_color_single_pixel(game, screen_row_id, screen_col_id, game->colors[0]);
			else 
				ft_color_single_pixel(game, screen_row_id, screen_col_id, game->colors[1]);
			screen_col_id++;
		}
		screen_row_id++;
	}
}

void	ft_ray_cast(t_game *game)
{
	// initialiser l'indicateur de visée sur une porte ouverte à 0
	ft_draw_floor_and_ceiling(game);
	game->ray->aiming_at_open_door = 0;
	game->ray->aiming_at_door = 0;
	game->ray->x = 0;
	while (game->ray->x < WIDTH)
	{
		ft_init_new_ray(game);
		ft_init_new_ray_dists(game);
		ft_loop_ray_until_a_hit(game);
		ft_get_wall_direction_hit(game);
		ft_init_line(game);
		ft_draw_wall_line(game);
		game->ray->x++;
	}
}
