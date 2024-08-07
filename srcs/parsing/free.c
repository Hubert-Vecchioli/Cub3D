/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebesnoin <ebesnoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:29:57 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/07 09:58:05 by ebesnoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_split(char ***split)
{
	int	i;

	i = 0;
	if (*split)
	{
		while ((*split) && (*split)[i])
		{
			free((*split)[i]);
			i++;
		}
		free((*split));
	}
}

static void	free_int_tab(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}

void	free_texture(char **texture)
{
	int	i;

	if (!texture)
		return ;
	i = 0;
	while (i < 4)
	{
		free(texture[i]);
		i++;
	}
	free(texture);
}

void	ft_free_game(t_game *game)
{
	free(game->hud);
	free(game->minimap);
	free(game->line);
	free(game->imgs);
	free(game->player);
	free(game->ray);
	ft_free_split(&game->map);
	free_texture(game->texture_paths);
	free(game);
}

void	ft_free_all(t_game *game)
{
	if (game->window)
	{
		mlx_clear_window(game->mlx_ptr, game->window);
		mlx_destroy_image(game->mlx_ptr, game->imgs->img);
		mlx_destroy_window(game->mlx_ptr, game->window);
		mlx_destroy_display(game->mlx_ptr);
		free_int_tab(game->textures, 4 + BONUS);
		free(game->mlx_ptr);
		free(game->hud->frames[0].addr_int);
		free(game->hud->frames[1].addr_int);
		free(game->hud->frames[2].addr_int);
		free(game->hud->frames[3].addr_int);
		free(game->hud->frames);
	}
	ft_free_game(game);
}
