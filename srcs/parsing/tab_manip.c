/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:29:01 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 12:03:04 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// void	ft_fill_square_map(char **new_map, char **map, int max_row_len)
// {
// 	int	row_id;
// 	int	col_id;
// 	int	map_row_length;

// 	row_id = 0;
// 	while (new_map[row_id])
// 	{
// 		col_id = 0;
// 		map_row_length = ft_strlen(map[row_id]) - 1;
// 		while (col_id < max_row_len)
// 		{
// 			if (col_id > map_row_length || (map[row_id][col_id] && map[row_id][col_id] == ' '))
// 				new_map[row_id][col_id] = '2';
// 			else
// 				new_map[row_id][col_id] = map[row_id][col_id];
// 			col_id++;
// 		}
// 		row_id++;
// 	}
// }

// void	ft_convert_map_to_square(t_game *game)
// {
// 	int		max_row_len;
// 	char	**new_map;
// 	int		i;
// 	int		len;

// 	i = 0;
// 	len = ft_tablen(game->map);
// 	max_row_len = get_max_row_len(game->map);
// 	new_map = ft_calloc(len + 1, sizeof(char *));
// 	if (!new_map)
// 		ft_error_exit("Error: malloc failure", game);
// 	while (i < len)
// 	{
// 		new_map[i] = ft_calloc(max_row_len + 1, sizeof(char));
// 		if (!new_map[i - 1])
// 		{
// 			ft_free_split(&new_map);
// 			ft_error_exit("Error: malloc failure", game);
// 		}
// 		i++;
// 	}
// 	new_map[i] = 0;
// 	ft_fill_square_map(new_map, game->map, max_row_len);
// 	ft_free_split(&game->map);
// 	game->map = new_map;
// }

char	**ft_remove_row(char **split, int i)
{
	char	**new;
	int		j;
	int		k;

	j = 0;
	k = 0;
	new = ft_calloc(ft_tablen(split) + 2, sizeof(char *)); // not to many rows?
	if (!new)
		return (NULL);
	while (split[j] && j != i)
	{
		new[k++] = ft_strdup(split[j]);
		j++;
	}
	j++;
	while (split[j])
	{
		new[k++] = ft_strdup(split[j]);
		j++;
	}
	new[k] = 0;
	ft_free_split(&split);
	return (new);
}

char	**del_nfirst(int n, char **map)
{
	char	**new_map;
	int		i;
	int		j;
	int		old_map_len;

	i = 0;
	j = n;
	old_map_len = ft_tablen(map);
	new_map = ft_calloc(old_map_len - n + 1, sizeof(char *));
	while (i < old_map_len - n)
	{
		new_map[i] = ft_strdup(map[j]);
		i++;
		j++;
	}
	ft_free_split(&map);
	return (new_map);
}

static int	ft_count_top_empty_rows(char **map)
{
	int	row_id;
	int	col_id;

	row_id = 0;
	col_id = 0;
	while (map[row_id])
	{
		while (map[row_id][col_id])
		{
			if (!ft_iswhitespace(map[row_id][col_id]))
				return (row_id);
			col_id++;
		}
		row_id++;
	}
	return (row_id);
}

void	ft_remove_empty_rows(t_game *game)
{
	char	**new_map;
	int		i;
	int		count_empty_rows;
	int		old_map_len;

	i = 0;
	count_empty_rows = ft_count_top_empty_rows(game->map);
	old_map_len = ft_tablen(game->map);
	new_map = ft_calloc(old_map_len - count_empty_rows + 1, sizeof(char *));
	if (!new_map)
		ft_error_exit("Error: malloc failure", game);
	while (i < (old_map_len - count_empty_rows))
	{
		new_map[i] = ft_strdup(game->map[i + count_empty_rows]);
		if (!new_map[i])
		{
			ft_free_split(&new_map);
			ft_error_exit("Error: malloc failure", game);
		}
		i++;
	}
	new_map[i] = 0;
	ft_free_split(&game->map);
	game->map = new_map;
}
