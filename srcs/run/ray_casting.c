/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:47:02 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 17:28:18 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/**/
// passer le x

static void	ft_draw_floor_and_ceiling(t_game *game) 
{
	int	screen_col_id;
	int	screen_row_id;

	screen_row_id = 0;
	screen_col_id = 0;
	while (screen_row_id < WIDTH)
	{
		while (screen_col_id < HEIGHT)
		{
			if (screen_col_id <= HEIGHT / 2)
				ft_color_single_pixel(game, screen_row_id, screen_col_id, game->colors[0]);
			else 
				ft_color_single_pixel(game, screen_row_id, screen_col_id, game->colors[1]);
			screen_col_id++;
		}
		screen_row_id++;
	}
}

void	ft_ray_cast(t_game *game)
{
	// initialiser l'indicateur de visée sur une porte ouverte à 0
	ft_draw_floor_and_ceiling(game);
	// loop tant que j'ai pas couvert mon ecran
	{
		// initialiser les variables du rayon
		 // initialiser les distances du rayon
		 // loop sur l'algorithme DDA jusqu'à ce qu'un mur soit frappé
		 // initialiser la position x du mur frappé
			// Initialiser les variables de la ligne à dessiner
		// dessiner la ligne texturée pour ce rayon
		// passer à la colonne suivante
	}
	 // déterminer si le joueur vise une porte ouverte ou une porte en général afin de savoir si on pourra l'ouvrir à l'avenir
}
