/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:28:24 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 13:55:54 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_reset_ray_parameters(t_game *game)
{
	// TODO reset the paramters !
	return ;
}

void	ft_get_player_initial_view(t_game *game)
{
	ft_get_player_position(game);
	if (game->map[(int)game->player->posx][(int)game->player->posy] == 'N')
		ft_player_north_spawn(game);
	else if (game->map[(int)game->player->posx][(int)game->player->posy] == 'S')
		ft_player_south_spawn(game);
	else if (game->map[(int)game->player->posx][(int)game->player->posy] == 'E')
		ft_player_east_spawn(game);
	else if (game->map[(int)game->player->posx][(int)game->player->posy] == 'W')
		ft_player_west_spawn(game);
}

void	ft_get_player_position(t_game *game)
{
	int	row_id;
	int	col_id;

	row_id = 0;
	while (game->map[row_id])
	{
		col_id = 0;
		while (game->map[row_id][col_id])
		{
			if (game->map[row_id][col_id] == 'N' || game->map[row_id][col_id] == 'S'
				|| game->map[row_id][col_id] == 'E' || game->map[row_id][col_id] == 'W')
			{
				game->player->posx = row_id + 0.5;
				game->player->posy = col_id + 0.5;
				return ;
			}
			col_id++;
		}
		row_id++;
	}
}

int	*ft_xpm_to_tab(t_game *game, int *width, int *height, char *path)
{
	t_img_data	tmp;
	int			*buffer;
	int			x;
	int			y;

	tmp.img = mlx_xpm_file_to_image(game->mlx_ptr, path, width, height);
	if (!tmp.img)
		ft_error_exit("Error: impossible to load", game);
	tmp.addr_int = (int *)mlx_get_game_addr(tmp.img, &tmp.bpp, &tmp.line_lengh,
			&tmp.endian);
	buffer = ft_calloc(1, sizeof * buffer * *width * *height);
	if (!buffer)
		ft_error_exit("Error, malloc failure", game);
	y = -1;
	while (++y < *height)
	{
		x = 0;
		while (x < *width)
		{
			buffer[y * *width + x] = tmp.addr_int[y * *width + x];
			++x;
		}
	}
	mlx_destroy_image(game->mlx_ptr, tmp.img);
	return (buffer);
}

void	ft_init_imgs(t_game *game)
{
	game->textures = ft_calloc(5 + BONUS, sizeof(int *));
	if (!game->textures)
		ft_error_exit("Error: malloc failure", game);
	game->textures[0] = xpm_to_tab(game, &game->tex_size, &game->tex_size,
			game->texture_paths[0]);
	game->textures[1] = xpm_to_tab(game, &game->tex_size, &game->tex_size,
			game->texture_paths[1]);
	game->textures[2] = xpm_to_tab(game, &game->tex_size, &game->tex_size,
			game->texture_paths[2]);
	game->textures[3] = xpm_to_tab(game, &game->tex_size, &game->tex_size,
			game->texture_paths[3]);
	if (BONUS)
		game->textures[4] = xpm_to_tab(game, &game->tex_size,
				&game->tex_size, "./textures/blackstone.xpm");
	ft_init_weapon_sprites(game);
}
