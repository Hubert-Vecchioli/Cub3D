/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:07:08 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 19:36:37 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_parse_game(char **av, t_game *game)
{
	int		map_fd;

	map_fd = 0;
	ft_get_fd(av[1], game, &map_fd);
	ft_get_raw_input(av, map_fd, game);
	ft_check_input_order(game);
	ft_get_texture_paths(game);
	ft_get_colors(game);
	ft_has_a_single_player(game);
	ft_remove_empty_rows(game);
	ft_is_map_closed(game);
	ft_has_another_map_below(game);
	return (1);
}
