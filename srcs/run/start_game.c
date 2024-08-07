/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:05:15 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/07 11:18:22 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_init_start_game(t_game *game)
{
	ft_get_player_initial_view(game);
	ft_init_hud_animation(game);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_error_exit("Error: minilibx failed to init", game);
	game->window = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!game->window)
		ft_error_exit("Error: minilibx failed to init a window", game);
	game->imgs->img = mlx_new_image(game->mlx_ptr, WIDTH, HEIGHT);
	if (!game->imgs->img)
		ft_error_exit("Error: minilibx failed to init images", game);
	game->imgs->addr = mlx_get_data_addr(game->imgs->img,
			&game->imgs->bits_per_pixel,
			&game->imgs->line_lengh, &game->imgs->endian);
	if (!game->imgs->addr)
		ft_error_exit("Error: minilibx failed to init an img addr", game);
	ft_init_imgs(game);
}

int	ray_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_update_player_view(game);
	ft_update_player_position(game);
	ft_reset_ray_parameters(game);
	ft_ray_cast(game);
	if (BONUS)
	{
		ft_add_aim_point(game, 0xFFFFFF, 5);
		ft_add_aim_point(game, 0xFFFFFF, 4);
		ft_add_weapon(game);
	}
	if (game->imgs->img)
		mlx_put_image_to_window(game->mlx_ptr, game->window,
			game->imgs->img, 0, 0);
	if (BONUS)
		ft_minimap(game);
	return (1);
}

void	ft_start_game(t_game *game)
{
	ft_init_start_game(game);
	mlx_hook(game->window, DestroyNotify, ButtonPressMask,
		ft_window_close, game);
	mlx_hook(game->window, KeyPress, KeyPressMask, ft_on_keypress, game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, ft_on_key_release,
		game);
	if (BONUS)
	{
		mlx_hook(game->window, MotionNotify, PointerMotionMask,
			ft_hook_on_mousemove, game);
		mlx_mouse_hook(game->window, ft_on_mouse_click, game);
	}
	mlx_loop_hook(game->mlx_ptr, &ray_loop, (void *)game);
	mlx_loop(game->mlx_ptr);
}
