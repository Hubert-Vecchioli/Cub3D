/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:10:27 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 19:40:06 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_get_time(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL) == -1)
		ft_putendl_fd(" Error getting time ", 2);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	ft_add_aim_point(t_game *game, int color, int radius)
{
	int		center_x;
	int		center_y;
	double	angle;
	int		x;
	int		y;

	angle = 0.0;
	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	while (angle < 2 * M_PI)
	{
		x = center_x + (int)(radius * cos(angle));
		y = center_y + (int)(radius * sin(angle));
		ft_color_single_pixel(game, x, y, color);
		angle += 0.01;
	}
	ft_color_single_pixel(game, center_x, center_y, color);
}

void	ft_init_hud_animation(t_game *game)
{
	game->hud = ft_calloc(2, sizeof(t_hud));
	if (!game->hud)
		ft_error_exit("Error: HUD malloc failure", game);
	game->hud->frames = ft_calloc(5, sizeof(t_img_data));
	if (!game->hud->frames)
		ft_error_exit("Error: HUD frames malloc failure", game);
	game->hud->animation_screen = 0;
}
