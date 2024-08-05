/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:43:45 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 12:13:03 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void ft_get_view_math(t_game *game, double rotation_speed)
{
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = game->player->direction_x;
	old_plane_x = game->player->user_screen_x;
	game->player->direction_x = old_dir_x * cos(rotation_speed) - game->player->direction_y * sin(rotation_speed);
	game->player->direction_y = old_dir_x * sin(rotation_speed) + game->player->direction_y * cos(rotation_speed);
	game->player->user_screen_x = old_plane_x * cos(rotation_speed) - game->player->user_screen_y * sin(rotation_speed);
	game->player->user_screen_y = old_plane_x * sin(rotation_speed) + game->player->user_screen_y * cos(rotation_speed);
}
void	ft_update_player_view(t_game *game)
{
	if (game->player->camera_moved_x)
		ft_get_view_math(game, ROTATION_SPEED);
	if (game->player->camera_moved_y)
		ft_get_view_math(game, ROTATION_SPEED * -1);
	return ;
}

int	ft_hook_on_mousemove(int x, int y, t_game *game)
{
	(void)y;
	if (x > WIDTH/2) 
		ft_get_view_math(game, (ROTATION_SPEED * (0.01 * ((float)WIDTH / 2 - x)) / 4));
	else if (x < WIDTH/2)
		ft_get_view_math(game, (-ROTATION_SPEED * (0.01 * (x - ((float)WIDTH / 2))) / 4));
	mlx_mouse_move(game->mlx_ptr, game->window, WIDTH / 2, HEIGHT / 2);
	return (0);
	
}

int	ft_on_mouse_click(int keycode, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		game->hud->animation_screen = 1;
	return (0);
}
