/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:18:14 by scely             #+#    #+#             */
/*   Updated: 2024/05/30 11:14:48 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx/mlx.h"
# include "libft.h"
# include <math.h>

# define SCREEN_W 700
# define SCREEN_H 700
# define MOVE_SPEED 0.95
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
	// position du joueur
	double				pos_x;
	double				pos_y;

	double				dir_x;
	double				dir_y;
	// couleur
	int					ciel;
	int					floor;
	// fov
	double				plane_x;
	double				plane_y;
}						t_ray;

typedef struct s_parsing
{
	char				*NO;
	char				*SO;
	char				*WE;
	char				*EA;

	int					floor[3];
	int					ciel[3];

	char				**maps;
	int					sens;
}						t_parsing;

typedef struct s_data
{
	struct s_parsing	pars;
	struct s_ray		ray;
	struct s_mlx		mlx;

}						t_data;

int						castray(t_data *data);
void					made_mouv(t_data *data, int keycode);
void					rotate_left(t_data *data);
void					rotate_right(t_data *data);
int						init_img(t_data *data);
int						cast_floor(t_data *data);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					free_img(t_data *data);
void					free_mlx(t_data *data);
int						close_window(t_data *data);
void free_mlx(t_data *data);
int	close_window(t_data *data);
void init_data(t_data *data);



#endif