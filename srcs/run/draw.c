/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:29:25 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 18:43:54 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_color_single_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH && y < HEIGHT && y > 0 && x > 0)
	{
		dst = game->imgs->addr + (y * game->imgs->line_lengh + x
				* (game->imgs->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
