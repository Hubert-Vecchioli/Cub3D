/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:03:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 19:30:14 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_reverse_strcmp(char *str, char *cmp)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = ft_strlen(cmp) - 1;
	while (j >= 0 && i >= 0 && str[i] && cmp[j])
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
