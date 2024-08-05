/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 10:31:58 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 16:57:30 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_on_keypress(int keycode, t_game *game)
{
	if (keycode == E_KEY)
		ft_door_action(game); 
	if (keycode == ARROW_LEFT)
		game->player->camera_moved_x = 1;
	if (keycode == ARROW_RIGHT)
		game->player->camera_moved_y = 1;
	if (keycode == W_KEY)
		game->player->has_moved_y = 1;
	if (keycode == S_KEY)
		game->player->has_moved_y = -1;
	if (keycode == D_KEY)
		game->player->has_moved_x = 1;
	if (keycode == A_KEY)
		game->player->has_moved_x = -1;
	if (keycode == KEY_ESC)
	{
		ft_putendl_fd("Closing the window - See you soon!", 1);
		close_and_exit(game);	
	}
	return (0);
}

int	ft_on_key_release(int keycode, t_game *game)
{
	if (keycode == ARROW_LEFT)
		game->player->camera_moved_x = 0;
	if (keycode == ARROW_RIGHT)
		game->player->camera_moved_y = 0;
	if (keycode == W_KEY)
		game->player->has_moved_y = 0;
	if (keycode == S_KEY)
		game->player->has_moved_y = 0;
	if (keycode == D_KEY)
		game->player->has_moved_x = 0;
	if (keycode == A_KEY)
		game->player->has_moved_x = 0;
	return (0);
}
