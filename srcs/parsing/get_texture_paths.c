/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:55:19 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 12:03:00 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_get_direction_id(char *str)
{
	if (!ft_strncmp(str, "NO", 2))
		return (0);
	if (!ft_strncmp(str, "SO", 2))
		return (1);
	if (!ft_strncmp(str, "WE", 2))
		return (2);
	if (!ft_strncmp(str, "EA", 2))
		return (3);
	return (-1);
}

static int	ft_test_texture_path(t_game *game)
{
	int	tmp_fd;
	int	i;

	i = 0;
	while (i < 4)
	{
		if (ft_reverse_strcmp(game->texture_paths[i], ".xpm") == -1)
			ft_error_exit("Error: texure file has no .xpm", game);	
		tmp_fd = open(game->texture_paths[i], O_RDONLY);
		if (tmp_fd == -1)
			ft_error_exit("Error: texture path can not be open", game);	
		close(tmp_fd);
		i++;
	}
	return (1);
}

static void	ft_parse_texture_path(t_game *game, int *i, int *count_dir)
{
	int	col_id;
	int	dir_id;

	col_id = ft_count_whitespaces(game->map[*i]);
	dir_id = ft_get_direction_id(&game->map[*i][col_id]);
	if (dir_id != -1)
	{
		col_id += 2;
		col_id += ft_count_whitespaces(&game->map[*i][col_id]);
		if (game->texture_paths[dir_id])
			ft_error_exit("Error: texture element already defined", game);
		game->texture_paths[dir_id] = ft_substr(game->map[*i], col_id,
				ft_strlen(game->map[*i]) - 3);
		if (!game->texture_paths[dir_id])
			ft_error_exit("Error: malloc failure", game);
		game->map = ft_remove_row(game->map, *i);
		if (!game->map)
			ft_error_exit("Error: malloc failure", game);
		(*count_dir)++;
		*i = 0;
	}
	else
		(*i)++;
}

int	ft_get_texture_paths(t_game *game)
{
	int	i;
	int	count_dir;

	i = 0;
	count_dir = 0;
	game->texture_paths = ft_calloc(5, sizeof(char *));
	if (!game->texture_paths)
		ft_error_exit("Error: map malloc failure", game);
	while (game->map[i])
		ft_parse_texture_path(game, &i, &count_dir);
	if (count_dir != 4)
		ft_error_exit("Error: missing textures in input", game);
	ft_test_texture_path(game);
	return (1);
}
