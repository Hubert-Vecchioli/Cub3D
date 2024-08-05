/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:15:33 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 12:04:37 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_count_map_rows(int *map_fd)
{
	int		i;
	char	*line;

	i = 0;
	while (1)
	{
		line = get_next_line(*map_fd);
		i++;
		if (!line)
			break ;
		free(line);
	}
	close(*map_fd);
	return (i);
}

int	ft_get_raw_input(char **av, int map_fd, t_game *game)
{
	int		i;

	i = ft_count_map_rows(&map_fd); // if (i <= 2)	mettre une erreur d'office ?
	game->map = malloc(sizeof(char *) * (i + 1));
	if (!game->map)
		ft_error_exit("Error: map malloc failure", game);
	ft_get_fd(av[1], game, &map_fd);
	i = 0;
	while (1)
	{
		game->map[i] = get_next_line(map_fd); // verifuer abscence de /n
		if (!game->map[i])
			break ;
		i++;
	}
	game->map[i] = 0;
	close(map_fd);
	return (1);
}