/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:18:14 by scely             #+#    #+#             */
/*   Updated: 2024/05/29 12:21:06 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

# define SCREEN_W 700
# define SCREEN_H 700
# define MOVE_SPEED 0.5
# define ROT_SPEED 0.5

//key press
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

typedef struct s_mlx
{
	void				*ptr;
	void				*win;

	void				*img;
	char *adrr;
	int bpp;
	int l_length;
	int endian;

	void				*img_one;
	void				*img_two;
	void				*img_three;
	void				*img_four;
}						t_mlx;

typedef struct s_ray
{
	// position du joueur
	double				pos_x;
	double				pos_y;

	// vector [sens initial du joueur x:y]
	// EST = 1:0 | WEST = -1:0 | NORTH = 0:1 | SOUTH 0:-1
	double				dir_x;
	double				dir_y;

	// fov
	double				plane_x;
	double				plane_y;

	// fps (useless)
	double				time;
	double				oldtime;
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
	char				sens;
}						t_parsing;

typedef struct s_data
{
	struct s_parsing	pars;
	struct s_ray		ray;
	struct s_mlx		mlx;

}						t_data;

void	castray(t_data *data);
void	made_mouv(t_data *data, int keycode);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);



#endif