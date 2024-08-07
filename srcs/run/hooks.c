/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebesnoin <ebesnoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 22:12:34 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/07 10:48:48 by ebesnoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	close_and_exit(t_game *game)
{
	ft_free_all(game);
	exit(1);
}

int	ft_window_close(t_game *game)
{
	ft_putendl_fd("Closing window - See you soon!", 1);
	close_and_exit(game);
	return (0);
}
