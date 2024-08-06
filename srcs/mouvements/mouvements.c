/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:29:57 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 07:41:55 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_door_action(t_game *game)
{
 if (game->ray->aiming_at_door)
   {
       game->map[game->ray->door_pos_x][game->ray->door_pos_y] = 'W';
   }
   if (game->ray->aiming_at_open_door && (game->ray->door_pos_x
   		!= game->player->posx || game->ray->door_pos_y != game->player->posy))
   {
       game->map[game->ray->door_pos_x][game->ray->door_pos_y] = 'D';
   }

}

static void	ft_move_y_plus(t_game *game)
{
	if (game->player->has_moved_y == 1 && game->map[(int)(game->player->posx + game->player->direction_x
			* MOVESPEED)][(int)(game->player->posy + game->player->direction_y
			* MOVESPEED)] != '1' && (BONUS == 0
			|| (game->map[(int)(game->player->posx + game->player->direction_x
					* MOVESPEED)][(int)(game->player->posy + game->player->direction_y
					* MOVESPEED)]) != 'D'))
	{
		game->player->posx = game->player->posx + game->player->direction_x * MOVESPEED;
		game->player->posy = game->player->posy + game->player->direction_y * MOVESPEED;
	}
}

static void	ft_move_y_minus(t_game *game)
{
	if (game->player->has_moved_y == -1 && game->map[(int)(game->player->posx - game->player->direction_x
			* MOVESPEED)][(int)(game->player->posy - game->player->direction_y
			* MOVESPEED)] != '1' && (BONUS == 0
			|| game->map[(int)(game->player->posx - game->player->direction_x
				* MOVESPEED)][(int)(game->player->posy - game->player->direction_y
				* MOVESPEED)] != 'D'))
	{
		game->player->posx = game->player->posx - game->player->direction_x * MOVESPEED;
		game->player->posy = game->player->posy - game->player->direction_y * MOVESPEED;
	}
}

static void	ft_move_x_plus(t_game *game)
{
	if (game->player->has_moved_x == 1 && game->map[(int)(game->player->posx + game->player->direction_y
			* MOVESPEED)][(int)(game->player->posy - game->player->direction_x
			* MOVESPEED)] != '1' && (BONUS == 0
			|| game->map[(int)(game->player->posx + game->player->direction_y
				* MOVESPEED)][(int)(game->player->posy - game->player->direction_x
				* MOVESPEED)] != 'D'))
	{
		game->player->posx = game->player->posx + game->player->direction_y * MOVESPEED;
		game->player->posy = game->player->posy - game->player->direction_x * MOVESPEED;
	}
}

static void	ft_move_x_minus(t_game *game)
{

	if (game->player->has_moved_x == -1 && game->map[(int)(game->player->posx - game->player->direction_y
			* MOVESPEED)][(int)(game->player->posy + game->player->direction_x
			* MOVESPEED)] != '1' && (BONUS == 0
			|| game->map[(int)(game->player->posx - game->player->direction_y
				* MOVESPEED)][(int)(game->player->posy + game->player->direction_x
				* MOVESPEED)] != 'D'))
	{
		game->player->posx = game->player->posx - game->player->direction_y * MOVESPEED;
		game->player->posy = game->player->posy + game->player->direction_x * MOVESPEED;
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
