/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebesnoin <ebesnoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:03:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 11:30:57 by ebesnoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdlib.h>

int	ft_reverse_strcmp(char *str, char *cmp)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(cmp) - 1;
	while (j >= 0 && str[i] && cmp[j])
	{
		if (str[i] != cmp[j])
			return (-1);
		j--;
		i--;
	}
	return (1);
}

void	ft_get_fd(char *map, t_game *game, int *fd)
{
	*fd = 0;
	if (ft_reverse_strcmp(map, ".cub") == -1)
		ft_error_exit("Error: the provided argument is not a .cub file", game);
	*fd = open(map, O_RDONLY);
	if (*fd == -1)
		ft_error_exit("Error: the provided argument's path has an error", game);
}

void	ft_error_exit(char *error, t_game *game)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	ft_free_all(game);
	exit(1);
}

int	ft_count_whitespaces(char *str)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	return (i);
}

int	ft_count_digits(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int	ft_get_max_map_width(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > count)
			count = j;
		i++;
	}
	return (count);
}

int	ft_valid_color(t_game *game, int row_id, int *col_id, int comma)
{
	*col_id += ft_count_whitespaces(&game->map[row_id][*col_id]);
	if (!ft_count_digits(&game->map[row_id][*col_id]))
		return (0);
	*col_id += ft_count_digits(&game->map[row_id][*col_id]);
	*col_id += ft_count_whitespaces(&game->map[row_id][*col_id]);
	if (comma && game->map[row_id][*col_id] != ',')
		return (0);
	else if (!comma && game->map[row_id][*col_id] != '\0')
		return (0);
	*col_id += 1;
	return (1);
}
