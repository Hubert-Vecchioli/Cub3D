/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 07:10:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 19:30:58 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_is_map_row(char *str)
{
	int		i;
	size_t	num;
	size_t	ws;

	i = 0;
	num = 0;
	ws = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			num++;
		if (ft_iswhitespace(str[i]) == 1)
			ws++;
		i++;
	}
	if (num != 0 && (num + ws) == ft_strlen(str))
		return (1);
	return (0);
}

int	ft_get_first_map_row(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (ft_is_map_row(game->map[i]) == 1)
			return (i);
		i++;
	}
	return (0);
}

static int	ft_element_has_premap_prefix(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strnstr(str, "NO", ft_strlen(str))
			|| ft_strnstr(str, "SO", ft_strlen(str))
			|| ft_strnstr(str, "WE", ft_strlen(str))
			|| ft_strnstr(str, "EA", ft_strlen(str))
			|| ft_strnstr(str, "F", ft_strlen(str))
			|| ft_strnstr(str, "C", ft_strlen(str)))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_input_order(t_game *game)
{
	int	i;
	int	first_row;

	i = 0;
	first_row = ft_get_first_map_row(game);
	while (game->map[i])
	{
		if (ft_element_has_premap_prefix(game->map[i]))
		{
			if (i > first_row)
				ft_error_exit("Error: The input has a \
wrong order or no map", game);
		}
		i++;
	}
	return (1);
}
