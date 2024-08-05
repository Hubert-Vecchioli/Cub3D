/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:39:24 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 12:03:05 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_player_north_spawn(t_game *game)
{
	game->player->direction_x = -1;
	game->player->direction_y = 0;
	game->player->user_screen_x = 0;
	game->player->user_screen_y = 0.66;
}

void	ft_player_south_spawn(t_game *game)
{
	game->player->direction_x = 1;
	game->player->direction_y = 0;
	game->player->user_screen_x = 0;
	game->player->user_screen_y = -0.66;
}

void	ft_player_west_spawn(t_game *game)
{
	game->player->direction_x = 0;
	game->player->direction_y = -1;
	game->player->user_screen_x = -0.66;
	game->player->user_screen_y = 0;
}

void	ft_player_east_spawn(t_game *game)
{
	game->player->direction_x = 0;
	game->player->direction_y = 1;
	game->player->user_screen_x = 0.66;
	game->player->user_screen_y = 0;
}
