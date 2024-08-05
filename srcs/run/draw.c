/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:29:25 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 12:10:03 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_color_single_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH && y < HEIGHT && y > 0 && x > 0)
	{
		dst = game->imgs->addr + (y * game->imgs->line_lengh + x
				* (game->imgs->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_restet_screen_display(t_game *game)
{
	// je recouvre mais à voir si je ne destroy pas l'image precedente?
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ft_color_single_pixel(game, i, j, 0x000000);
			j++;
		}
		i++;
	}
}
