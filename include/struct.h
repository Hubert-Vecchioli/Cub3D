/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebesnoin <ebesnoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 03:08:23 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/05 18:18:42 by ebesnoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

// LINUX
# define KEY_ESC			65307
# define KEY_Q				113
# define W_KEY				119
# define KEY_E				101
# define A_KEY				97
# define S_KEY				115
# define D_KEY				100
# define P_KEY				112
# define E_KEY				101
# define ARROW_UP			65362
# define ARROW_DOWN			65364
# define ARROW_LEFT			65361
# define ARROW_RIGHT		65363

typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

typedef struct s_minimap
{
	t_vector	pos;
	t_vector	size;
	t_vector	axe;
}	t_minimap;

typedef struct s_img_data
{
	void		*img;
	void		*addr;
	int			*addr_int;
	int			bpp;
	int			line_lengh;
	int			endian;
	int			width;
	int			height;
	int			not_printed_color;

}				t_img_data;

typedef struct s_line
{
	int			lineheight;
	int			x;
	int			y;
	int			y0;
	int			y1;
	int			tex_x;
	int			tex_y;
	int			tex_color;
	int			span;
	int			off;
}				t_line;

typedef struct s_player
{
	int			has_moved_x;
	int			has_moved_y;
	int			camera_moved_x;
	int			camera_moved_y;
	double		direction_x;
	double		direction_y;
	double		user_screen_x;
	double		user_screen_y;
	double		posx;
	double		posy;
}				t_player;

typedef struct s_hud
{
	t_img_data	*frames;
	int			animation_screen;
}				t_hud;

typedef struct s_ray
{
	/// TODO !! :) 
}				t_ray;

typedef struct s_game
{
	char		**map;
	char		**texture_paths;
	int			**textures;
	int			tex_size;
	int		colors[2];
	void		*mlx_ptr;
	void		*window;
	t_img_data	*imgs;
	t_player	*player;
	t_ray		*ray;
	t_minimap	*minimap;
	t_line		*line;
	t_hud		*hud;
}				t_game;

#endif
