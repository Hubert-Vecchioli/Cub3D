/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebesnoin <ebesnoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:29:57 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 19:44:26 by ebesnoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_move_y_plus(t_game *game)
{
	if (game->player->has_moved_y == 1 && game->map[(int)(game->player->posx
			+ game->player->direction_x * MOVESPEED)][(int)(game->player->posy
			+ game->player->direction_y * MOVESPEED)] != '1' && (BONUS == 0
			|| (game->map[(int)(game->player->posx + game->player->direction_x
			* MOVESPEED)][(int)(game->player->posy + game->player->direction_y
			* MOVESPEED)]) != 'D'))
	{
		game->player->posx = game->player->posx + game->player->direction_x
			* MOVESPEED;
		game->player->posy = game->player->posy + game->player->direction_y
			* MOVESPEED;
	}
}

static void	ft_move_y_minus(t_game *game)
{
	if (game->player->has_moved_y == -1 && game->map[(int)(game->player->posx
			- game->player->direction_x * MOVESPEED)][(int)(game->player->posy
			- game->player->direction_y * MOVESPEED)] != '1' && (BONUS == 0
			|| game->map[(int)(game->player->posx - game->player->direction_x
			* MOVESPEED)][(int)(game->player->posy - game->player->direction_y
			* MOVESPEED)] != 'D'))
	{
		game->player->posx = game->player->posx - game->player->direction_x
			* MOVESPEED;
		game->player->posy = game->player->posy - game->player->direction_y
			* MOVESPEED;
	}
}

static void	ft_move_x_plus(t_game *game)
{
	if (game->player->has_moved_x == 1 && game->map[(int)(game->player->posx
			+ game->player->direction_y * MOVESPEED)][(int)(game->player->posy
			- game->player->direction_x * MOVESPEED)] != '1' && (BONUS == 0
			|| game->map[(int)(game->player->posx + game->player->direction_y
			* MOVESPEED)][(int)(game->player->posy - game->player->direction_x
			* MOVESPEED)] != 'D'))
	{
		game->player->posx = game->player->posx + game->player->direction_y
			* MOVESPEED;
		game->player->posy = game->player->posy - game->player->direction_x
			* MOVESPEED;
	}
}

static void	ft_move_x_minus(t_game *game)
{
	if (game->player->has_moved_x == -1 && game->map[(int)(game->player->posx
			- game->player->direction_y * MOVESPEED)][(int)(game->player->posy
			+ game->player->direction_x * MOVESPEED)] != '1' && (BONUS == 0
			|| game->map[(int)(game->player->posx - game->player->direction_y
			* MOVESPEED)][(int)(game->player->posy + game->player->direction_x
			* MOVESPEED)] != 'D'))
	{
		game->player->posx = game->player->posx - game->player->direction_y
			* MOVESPEED;
		game->player->posy = game->player->posy + game->player->direction_x
			* MOVESPEED;
	}
}

void	ft_update_player_position(t_game *game)
{
	ft_move_y_plus(game);
	ft_move_y_minus(game);
	ft_move_x_plus(game);
	ft_move_x_minus(game);
	return ;
}
