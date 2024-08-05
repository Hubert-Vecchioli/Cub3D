/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:01:26 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 12:03:40 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_minimap_draw(t_game *game, t_vector mini_map_pos, t_vector mini_map_size)
{
	t_minimap	minimap;

	ft_memset(&minimap, 0, sizeof(t_minimap));
	minimap.axe.y = game->player->posy - 5;
	while (minimap.axe.y < game->player->posy + 5)
	{
		minimap.axe.x = game->player->posx - 5;
		while (minimap.axe.x < game->player->posx + 5)
		{
			if (minimap.axe.y >= 0 && minimap.axe.y < HEIGHT \
				&& minimap.axe.x >= 0 && minimap.axe.x < WIDTH)
				ft_minimap_actual_draw(game, mini_map_pos, mini_map_size, &minimap);
			++minimap.axe.x;
		}
		++minimap.axe.y;
	}
	draw_player(game, mini_map_pos, mini_map_size);
}


static void	ft_minimap_border(t_game *game, t_vector *mini_map_pos, \
	t_vector *mini_map_size)
{
	ft_draw_square(game, *mini_map_pos, *mini_map_size, 0x000000);
	(*mini_map_pos).x += 10;
	(*mini_map_pos).y += 10;
	(*mini_map_size).x -= 20;
	(*mini_map_size).y -= 20;
	ft_draw_square(game, *mini_map_pos, *mini_map_size, 0x808080);
}

static void	ft_minimap_size(t_game *game, t_vector *mini_map_size, t_vector *mini_map_pos)
{
	mini_map_size->x = WIDTH / 8;
	mini_map_size->y = mini_map_size->x;
	mini_map_pos->x = WIDTH - mini_map_size->x - 25;
	mini_map_pos->y = 25;
}

void	ft_minimap(t_game *game)
{
	t_vector	mini_map_size;
	t_vector	mini_map_pos;

	ft_minimap_size(game, &mini_map_size, &mini_map_pos);
	ft_minimap_border(game, &mini_map_pos, &mini_map_size);
	ft_minimap_draw(game, mini_map_pos, mini_map_size);
}