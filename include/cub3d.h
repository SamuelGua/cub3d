/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:18:14 by scely             #+#    #+#             */
/*   Updated: 2024/06/03 19:28:01 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "libft.h"
# include <math.h>

# define SCREEN_W 550
# define SCREEN_H 550
# define MOVE_SPEED 0.55
# define ROT_SPEED 0.25
# define IMG_H 64
# define IMG_W 64

// key press
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

typedef struct s_mlx
{
	void				*ptr;
	void				*win;

	void				*img;
	char				*adrr;
	int					bpp;
	int					l_length;
	int					endian;

	void				*img_no;
	void				*img_so;
	void				*img_ea;
	void				*img_we;
}						t_mlx;

typedef struct s_ray
{
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	int					ciel;
	int					floor;
	double				plane_x;
	double				plane_y;
}						t_ray;

typedef struct s_parsing
{
	char				*name;
	char				**map;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				sens;
	int					map_height;
	int					floor[3];
	int					ceiling[3];
	char				*stash;
}						t_parsing;

typedef struct s_data
{
	struct s_parsing	pars;
	struct s_ray		ray;
	struct s_mlx		mlx;

}						t_data;

typedef struct s_rutils
{
	double				camera_x;
	double				raydir_x;
	double				raydir_y;
	int					map_x;
	int					map_y;
	double				side_distx;
	double				side_disty;
	double				delta_distx;
	double				delta_disty;
	double				perpwall_dist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					x;
	int					y;
	void				*texture;
	double				wallx;
	int					tex_x;
	int					d;
	int					tex_y;
	int					color;

}						t_rutils;

int						castray(t_data *data);
void					made_mouv(t_data *data, int keycode);
void					rotate_left(t_data *data);
void					rotate_right(t_data *data);
int						init_img(t_data *data);
int						cast_floor(t_data *data);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					free_img(t_data *data);
void					free_mlx(t_data *data);
void					free_pars(t_data *data);
int						close_window(t_data *data);
void					free_mlx(t_data *data);
int						close_window(t_data *data);
void					init_data(t_data *data);
void					distanceview(t_rutils *utils, t_data *data);
void					set_textures(t_rutils *utils, t_data *data);
void					draw_all(t_rutils *utils, t_data *data);
void					set_value_init(t_rutils *utils, t_data *data);
void					setp_sidedist(t_rutils *utils, t_data *data);
void					dda_calcul(t_rutils *utils, t_data *data);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
int						get_texture_color(void *img, int tex_x, int tex_y);
int						get_data(t_parsing *data);
int						get_map(t_parsing *data);
int						checkformat(char *name, char *format);
int						get_check_all(t_parsing *data);
void					get_rgb(t_parsing *data, char *line);
void					get_texture(t_parsing *data, char **line, int fd);
int						goto_next_value(char *line);
char					*ft_strdup2(char *line);
int						is_only_digits_or_whitespace(char *str);
void					get_map_height(t_parsing *data, char **line, int fd);
int						get_data(t_parsing *data);
void					stock_line(t_parsing *data, char *line);
int						check_data(t_parsing *data);
int						check_data_texture(t_parsing *data);
void					free_all(t_parsing *data);
int						check_map_elem(char **map);
void					get_sens(t_parsing *data);
char					*skip_to_value(char *line);
int						check_map_wall(t_parsing *data, char **map_tab);
int						check_all_floor(t_parsing *data, char **map);
int						check_close_floor(t_parsing *data, char **map);
int						valid_rgb_line(char *line);
int						is_map2(int i, int j, t_parsing *data, char **map);
int						is_map(int i, int j, t_parsing *data, char **map);
void 					init_null(t_parsing *data);
int						ft_is_whitespaces(char *str);

#endif
