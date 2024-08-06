/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebesnoin <ebesnoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:42:22 by ebesnoin          #+#    #+#             */
/*   Updated: 2024/08/06 19:42:33 by ebesnoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_door_action(t_game *game)
{
	if (game->ray->aiming_at_door)
		game->map[game->ray->door_pos_x][game->ray->door_pos_y] = 'W';
	else if (game->ray->aiming_at_open_door && (game->ray->door_pos_x
			!= game->player->posx || game->ray->door_pos_y
			!= game->player->posy))
		game->map[game->ray->door_pos_x][game->ray->door_pos_y] = 'D';
}
