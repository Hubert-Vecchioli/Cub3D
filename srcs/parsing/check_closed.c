/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_closed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 22:38:40 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 18:28:59 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_map_has_surronding_leak(char **map, int i, int j)
{
	if ((j >= (int)ft_strlen(map[i - 1]) || ft_iswhitespace(map[i - 1][j - 1]) || !map[i - 1][j - 1])
		|| (j >= (int)ft_strlen(map[i - 1]) || ft_iswhitespace(map[i - 1][j]) || !map[i - 1][j])
		|| (j >= (int)ft_strlen(map[i - 1]) || ft_iswhitespace(map[i - 1][j + 1]) || !map[i - 1][j + 1])
		|| (j >= (int)ft_strlen(map[i]) || ft_iswhitespace(map[i][j - 1]) || !map[i][j - 1])
		|| (j >= (int)ft_strlen(map[i]) || ft_iswhitespace(map[i][j + 1]) || !map[i][j + 1])
		|| ((i + 1) >= (int)ft_tablen(map) || j >= (int)ft_strlen(map[i + 1]) || ft_iswhitespace(map[i + 1][j - 1]) || !map[i + 1][j - 1])
		|| ((i + 1) >= (int)ft_tablen(map) || j >= (int)ft_strlen(map[i + 1]) || ft_iswhitespace(map[i + 1][j]) || !map[i + 1][j])
		|| ((i + 1) >= (int)ft_tablen(map) || j >= (int)ft_strlen(map[i + 1]) || ft_iswhitespace(map[i + 1][j + 1])) || !map[i + 1][j + 1])
		return (1);
	return (0);
}

static int	ft_is_char_allowed_in_map(char c)
{
	if (BONUS == 1 && c == 'D')
		return (1);
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '1'
		&& c != '0')
		return (0);
	return (1);
}

int	ft_is_map_closed(t_game *game)
{
	int	row_id;
	int	col_id;

	row_id = 0;
	while (game->map[row_id])
	{
		col_id = 0;
		while (game->map[row_id][col_id])
		{
			if (game->map[row_id][col_id] == '0' || ft_is_player_direction(game->map[row_id][col_id]))
				if (row_id == 0 || col_id == 0 || row_id == (int)ft_tablen(game->map) || col_id == (int)ft_strlen(game->map[row_id]) ||ft_map_has_surronding_leak(game->map, row_id, col_id))
					ft_error_exit("Error: Map is not closed", game);
			col_id++;
		}
		row_id++;
	}
	return (1);
}

int	ft_has_a_single_player(t_game *game)
{
	int	row_id;
	int	col_id;
	int	count;

	row_id = 0;
	count = 0;
	while (game->map[row_id])
	{
		col_id = 0;
		while (game->map[row_id][col_id])
		{
			if (ft_is_player_direction(game->map[row_id][col_id]))
				count++;
			if (!ft_is_char_allowed_in_map(game->map[row_id][col_id]) && !ft_iswhitespace(game->map[row_id][col_id]))
				ft_error_exit("Error: Unauthorised char in map", game);
			col_id++;
		}
		row_id++;
	}
	if (count > 1)
		ft_error_exit("Error: More than 1 player in map", game);
	if (count < 1)
		ft_error_exit("Error: No player found in map", game);
	return (1);
}

int	ft_has_another_map_below(t_game *game)
{
	int	row_id;
	int	col_id;
	int	row_len;
	int	count_whitespaces;
	int	is_map_started;

	row_id = 0;
	while (game->map[row_id])
	{
		count_whitespaces = 0;
		col_id = 0;
		row_len = ft_strlen(game->map[row_id]);
		while (game->map[row_id][col_id])
		{
			if (ft_is_char_allowed_in_map(game->map[row_id][col_id]))
				is_map_started = 1;
			if (ft_iswhitespace(game->map[row_id][col_id]))
				count_whitespaces++;
			// et on fait quoi si on a des lignes de ' ' après la map ?? TODO: les retirer
			col_id++;
		}
		if (count_whitespaces == row_len && is_map_started)
			ft_error_exit("Error: the input has a second map below", game);
		row_id++;
	}
	return (1);
}
