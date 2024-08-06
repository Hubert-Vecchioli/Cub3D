/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 21:28:24 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 17:14:50 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_reset_ray_parameters(t_game *game)
{
	game->ray->x = 0;
	game->ray->camerax = 0;
	game->ray->raydirx = 0;
	game->ray->raydiry = 0;
	game->ray->distance_to_next_x = 0;
	game->ray->distance_to_next_y = 0;
	game->ray->distance_to_first_x = 0;
	game->ray->distance_to_first_y = 0;
	game->ray->perpwalldist = 0;
	game->ray->wall_x = 0;
	game->ray->mapx = 0;
	game->ray->mapy = 0;
	game->ray->stepx = 0;
	game->ray->stepy = 0;
	game->ray->side = 0;
	game->ray->hit = 0;
	game->ray->aiming_at_door = 0;
	game->ray->aiming_at_open_door = 0;
	game->ray->door_pos_x = 0;
	game->ray->door_pos_y = 0;
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
	t_img_data	temp;
	int			*tab;
	int			x;
	int			y;

	temp.img = mlx_xpm_file_to_image(game->mlx_ptr, path, width, height);
	if (!temp.img)
		ft_error_exit("Error: impossible to load", game);
	temp.addr_int = (int *)mlx_get_data_addr(temp.img, &temp.bits_per_pixel, &temp.line_lengh,
			&temp.endian);
	tab = ft_calloc(1, sizeof * tab * *width * *height);
	if (!tab)
		ft_error_exit("Error, malloc failure", game);
	y = -1;
	while (++y < *height)
	{
		x = 0;
		while (x < *width)
		{
			tab[y * *width + x] = temp.addr_int[y * *width + x];
			++x;
		}
	}
	mlx_destroy_image(game->mlx_ptr, temp.img);
	return (tab);
}

void	ft_init_imgs(t_game *game)
{
	game->textures = ft_calloc(5 + BONUS, sizeof(int *));
	if (!game->textures)
		ft_error_exit("Error: malloc failure", game);
	game->textures[0] = ft_xpm_to_tab(game, &game->tex_size, &game->tex_size,
			game->texture_paths[0]);
	game->textures[1] = ft_xpm_to_tab(game, &game->tex_size, &game->tex_size,
			game->texture_paths[1]);
	game->textures[2] = ft_xpm_to_tab(game, &game->tex_size, &game->tex_size,
			game->texture_paths[2]);
	game->textures[3] = ft_xpm_to_tab(game, &game->tex_size, &game->tex_size,
			game->texture_paths[3]);
	if (BONUS)
		game->textures[4] = ft_xpm_to_tab(game, &game->tex_size,
				&game->tex_size, "./textures/eagle.xpm");
	ft_init_weapon_sprites(game);
}
