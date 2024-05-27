/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scely <scely@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:18:14 by scely             #+#    #+#             */
/*   Updated: 2024/05/25 22:35:39 by scely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "../minilibx/mlx.h"
# include <math.h>

# define SCREEN_W 500
# define SCREEN_H 500

# define ESC 65307

typedef struct s_mlx
{
	void				*ptr;
	void				*win;

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

#endif