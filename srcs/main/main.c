/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:33:39 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 13:45:32 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_game	*ft_init_game(t_game *game)
{
	game = ft_calloc(2, sizeof(t_game));
	if (!game)
		ft_error_exit("Error: malloc failure", game); //verifier si pas d'erreur dans le free ?? je pense pas
	game->imgs = ft_calloc(2, sizeof(t_img_data));
	game->ray = ft_calloc(2, sizeof(t_ray)); // je sais pas ce que ce sera mais bon
	game->player = ft_calloc(2, sizeof(t_player));
	game->minimap = ft_calloc(2, sizeof(t_minimap));
	game->line = ft_calloc(2, sizeof(t_line));
	if (!game->imgs || !game->ray || !game->player || !game->minimap
		|| !game->line)
		ft_error_exit("Error: malloc failure", game);
	return (game);
}
int	main(int ac, char **av)
{
	t_game	*game;

	game = NULL;
	if (ac != 2)
		return(ft_putendl_fd("Error: cub3d requires a single argument", 2), 1);
	game = ft_init_game(game);
	ft_parse_game(av, game);
	ft_start_game(game);
	ft_free_all(game);
	return (0);
}
