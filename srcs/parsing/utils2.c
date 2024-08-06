/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:30:05 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 19:30:19 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
