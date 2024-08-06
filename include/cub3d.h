/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:53:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/08/06 19:36:49 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx-linux/mlx.h"
# include "../mlx-linux/mlx_int.h"
# include <sys/time.h>
# include <fcntl.h>
# include <math.h>
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "struct.h"

char			**del_nfirst(int n, char **map);
char			**ft_remove_row(char **split, int i);
int				ft_parse_game(char **av, t_game *game);
int				ft_get_raw_input(char **av, int map_fd, t_game *game);
int				ft_reverse_strcmp(char *str, char *cmp);
int				ft_check_input_order(t_game *game);
int				check_perms(t_game *game);
int				ft_get_texture_paths(t_game *game);
int				ft_get_color_id(char c);
int				ft_get_colors(t_game *game);
int				ft_count_whitespaces(char *str);
int				ft_map_has_surronding_leak(char **map, int i, int j);
int				ft_is_player_direction(char c);
int				ft_is_map_closed(t_game *game);
int				ft_has_a_single_player(t_game *game);
int				ft_has_another_map_below(t_game *game);
int				ft_get_max_map_width(char **map);
int				ft_window_close(t_game *game);
int				ft_on_keypress(int key, t_game *game);
int				ft_on_key_release(int keycode, t_game *game);
int				ft_on_mouse_click(int keycode, int x, int y, t_game *game);
int				ft_count_digits(char *str);
int				ft_hook_on_mousemove(int x, int y, t_game *game);
int				ft_get_time(void);
int				*ft_xpm_to_tab(t_game *game, int *width, \
int *height, char *path);
int				ft_valid_color(t_game *game, int row_id, \
int *col_id, int comma);
void			ft_ray_cast(t_game *game);
void			ft_door_action(t_game *game);
void			ft_add_weapon(t_game *game);
void			ft_player_north_spawn(t_game *game);
void			ft_player_south_spawn(t_game *game);
void			ft_player_west_spawn(t_game *game);
void			ft_player_east_spawn(t_game *game);
void			ft_get_player_position(t_game *game);
void			ft_get_player_initial_view(t_game *game);
void			ft_init_hud_animation(t_game *game);
void			ft_add_aim_point(t_game *game, int color, int r);
void			ft_reset_ray_parameters(t_game *game);
void			ft_update_player_position(t_game *game);
void			ft_update_player_view(t_game *game);
void			close_and_exit(t_game *game);
void			ft_init_imgs(t_game *game);
void			ft_init_weapon_sprites(t_game *game);
void			ft_free_split(char ***split);
void			ft_color_single_pixel(t_game *game, int x, int y, int color);
void			ft_remove_empty_rows(t_game *game);
void			draw_player(t_game *game, t_vector map_pos, t_vector map_size);
void			ft_minimap(t_game *game);
void			ft_free_all(t_game *game);
void			ft_start_game(t_game *game);
void			ft_get_fd(char *map, t_game *game, int *fd);
void			ft_error_exit(char *error, t_game *game);
void			ft_get_wall_direction_hit(t_game *game);
void			ft_init_line(t_game *game);
void			ft_draw_wall_line(t_game *game);
void			ft_loop_ray_until_a_hit_bonus(t_game *game);
void			ft_add_img_but_one_color(t_game *game, t_img_data img, \
int img_corner_x, int img_corner_y);
void			ft_minimap_actual_draw(t_game *game, t_vector mini_map_pos, \
t_vector mini_map_size, t_minimap *minimap);
void			ft_draw_square(t_game *game, t_vector start, t_vector end, \
int color);

#endif
