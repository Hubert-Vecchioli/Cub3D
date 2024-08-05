/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 00:30:35 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 12:03:02 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_count_numbers_in_row(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		while (!ft_isdigit(str[i]))
			i++;
		if (str[i])
			num++;
		while (ft_isdigit(str[i]))
			i++;
	}
	return (num);
}

static int	ft_review_color_format(char *str, int	i)
{
	int	count_coma;

	count_coma = 0;
	if (ft_count_numbers_in_row(str) != 3)
		return (0);
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && str[i] != ',')
			&& !ft_iswhitespace(str[i]))
			return (-1);
		if (str[i] == ',')
			count_coma++;
		i++;
	}
	if (count_coma != 2)
		return (0);
	return (1);
}

int	ft_convert_rgb_in_bytes(t_game *game, int row_id, int color_id, int col_id)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(&game->map[row_id][col_id]);
	col_id += ft_count_whitespaces(&game->map[row_id][col_id]);
	col_id += ft_count_digits(&game->map[row_id][col_id]);
	col_id += ft_count_whitespaces(&game->map[row_id][col_id]);
	if (game->map[row_id][col_id] == ',')
			col_id++;
	else 
		return (0);
	g = ft_atoi(&game->map[row_id][col_id]);
	col_id += ft_count_whitespaces(&game->map[row_id][col_id]);
	col_id += ft_count_digits(&game->map[row_id][col_id]);
	col_id += ft_count_whitespaces(&game->map[row_id][col_id]);
	if (game->map[row_id][col_id] == ',')
			col_id++;
	else 
		return (0);
	b = ft_atoi(&game->map[row_id][col_id]);
	game->colors[color_id] = (r << 16) + (g << 8) + (b);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		return (0);
	return (1);
}

// ATTENTION cas "XXX,XXX, " a traiter
static void	ft_parse_colors(t_game *game, int *row_id, int *count_colors)
{
	int	color_id;
	int	col_id;
	
	col_id = ft_count_whitespaces(game->map[*row_id]);
	color_id = ft_get_color_id(game->map[*row_id][col_id]);
	if (color_id != -1)
	{
		col_id += 1;
		if (game->colors[color_id])
			ft_error_exit("Error: color already defined", game);
		if (!ft_review_color_format(game->map[*row_id], col_id)
			|| !ft_convert_rgb_in_bytes(game, *row_id, color_id, col_id))
			ft_error_exit("Error: invalid color", game);
		game->map = ft_remove_row(game->map, *row_id);
		if (!game->map)
			ft_error_exit("Error: malloc failure", game);
		*count_colors = *count_colors + 1;
		*row_id = 0;
	}
	else
		*row_id = *row_id + 1;
}

int	ft_get_colors(t_game *game)
{
	int	row_id;
	int	count_colors;

	row_id = 0;
	count_colors = 0;
	game->colors[0] = 0;
	game->colors[1] = 0;
	while (game->map[row_id])
		ft_parse_colors(game, &row_id, &count_colors);
	if (count_colors != 2)
		ft_error_exit("Error: missing color in input", game);
	return (1);
}
