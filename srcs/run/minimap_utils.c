/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:23:12 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 12:04:47 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


static void	ft_minimap_actual_draw(t_game *game, t_vector mini_map_pos, \
t_vector mini_map_size, t_minimap *minimap)
{
	minimap->pos.x = mini_map_pos.x + (minimap->axe.x - game->player->posx + 5) \
		* mini_map_size.x / 10;
	minimap->pos.y = mini_map_pos.y + (minimap->axe.y - game->player->posy + 5) \
		* mini_map_size.y / 10;
	minimap->size.x = mini_map_size.x / 10;
	minimap->size.y = mini_map_size.y / 10;
	if (minimap->size.x > 0 && minimap->size.y > 0)
	{
		if (game->map[minimap->axe.y][minimap->axe.x] == '1')
			ft_draw_square(game, minimap->pos, minimap->size, 0x000000);
	}
}

void	ft_draw_square(t_game *game, t_vector start, t_vector end, \
int color)
{
	t_vector	reference;

	reference.x = start.x;
	reference.y = start.y;
	while ((start.y - reference.y) < end.y)
	{
		start.x = reference.x;
		while ((start.x - reference.x) < end.x)
		{
			ft_color_single_pixel(game, start.x, start.y, color);
			start.x++;
		}
		start.y++;
	}
}


void	draw_player(t_game *game, t_vector map_pos, t_vector map_size)
{	
	double	angle;
	t_vector	pos_player;
	t_vector	point;
	int		x;
	int		y;

	pos_player.x = map_pos.x + 5 * map_size.x / 10;
	pos_player.y = map_pos.y + 5 * map_size.y / 10;
	angle = 0;
	while (angle < 2 * M_PI)
	{
		point.x = (int)((double)(map_size.x / 40) * cos(angle)) + pos_player.x;
		point.y = (int)((double)(map_size.x / 40) * sin(angle)) + pos_player.y;
		ft_color_single_pixel(game, point.x, point.y, 0x00FF00);
		angle += 0.01;
	}
}
