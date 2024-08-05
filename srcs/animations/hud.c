/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 16:28:19 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 17:09:53 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_add_weapon(t_game *game)
{
	t_img_data	*fr;

	fr = game->hud->frames;
	if (game->hud->animation_screen && game->hud->animation_screen >= 1 
		&& game->hud->animation_screen < 4)
		ft_add_img_but_one_color(game, fr[1], WIDTH - fr[1].width
			- 50, HEIGHT - fr[1].height);
	else if (game->hud->animation_screen && game->hud->animation_screen >= 4 
		&& game->hud->animation_screen < 8)
		ft_add_img_but_one_color(game, fr[2], WIDTH - fr[2].width
			- 50, HEIGHT - fr[2].height);
	else if (game->hud->animation_screen && game->hud->animation_screen >= 8 
		&& game->hud->animation_screen < 12)
		ft_add_img_but_one_color(game, fr[3], WIDTH - fr[3].width
			- 50, HEIGHT - fr[3].height);
	else
	{
		game->hud->animation_screen = 0;
		ft_add_img_but_one_color(game, fr[0], WIDTH - fr[0].width - 50,
			HEIGHT - fr[0].height);
	}
	if (game->hud->animation_screen)
		game->hud->animation_screen++;
}

void	ft_init_weapon_sprites(t_game *game)
{
	int	w;
	int	h;
	int	i;

	w = 0;
	h = 0;
	game->hud->frames[0].addr_int = ft_xpm_to_tab(game, &w, &h,
			"./textures/gun_sprites/gun_idle.xpm");
	game->hud->frames[1].addr_int = ft_xpm_to_tab(game, &w, &h,
			"./textures/gun_sprites/gun_shoot00.xpm");
	game->hud->frames[2].addr_int = ft_xpm_to_tab(game, &w, &h,
			"./textures/gun_sprites/gun_shoot01.xpm");
	game->hud->frames[3].addr_int = ft_xpm_to_tab(game, &w, &h,
			"./textures/gun_sprites/gun_shoot02.xpm");
	i = 0;
	while (i < 4)
	{
		game->hud->frames[i].width = 512;
		game->hud->frames[i].height = 512;
		game->hud->frames[i].not_printed_color = -16777216; // perfect black ;)
		i++;
	}
}

void	ft_add_img_but_one_color(t_game *game, t_img_data img, int img_corner_x,
		int img_corner_y)
{
	int	img_row_id;
	int	img_col_id;

	img_row_id = 0;
	img_col_id = 0;
	while (img_row_id < img.height)
	{
		img_col_id = 0;
		while (img_col_id < img.width)
		{
			if (img.addr_int[img_row_id * img.width + img_col_id] != img.not_printed_color)
				ft_color_single_pixel(game, img_corner_x + img_col_id, img_corner_y + img_row_id, img.addr_int[img_row_id
					* img.width + img_col_id]);
			img_col_id++;
		}
		img_row_id++;
	}
}
