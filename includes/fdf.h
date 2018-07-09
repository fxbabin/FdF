/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:59:18 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/09 22:33:50 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDH_H
# define FDH_H

/*
 ** --------------------------------- INCLUDES -------------------------------
 */

# include "mlx.h"
# include "ft_printf.h"
# include "io.h"
# include "lst.h"
# include "array.h"

# define WIDTH 1380
# define HEIGHT 1380
# define BASE_WIDTH 400
# define BASE_HEIGHT 400

/*
 ** -------------------------------- STRUCTURES -------------------------------
 */

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_env
{
	int				**coords;
	int				**x;
	int				**y;
	int				**z;
	int				fd;
	int				base_width;
	int				base_height;
	int				base_z;
	int				net_size;
	int				nb_col;
	int				nb_lign;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_img;
	int				x_center;
	int				y_center;
	double			rot_x;
	double			rot_y;
	double			rot_z;
	unsigned int	*img;
}					t_env;

/*
 ** ----------------------------------------------------------------------------
 ** ---------------------------------- SOURCES ---------------------------------
 ** ----------------------------------------------------------------------------
 */

int				get_coords(t_env *env);
void			ft_int22dump(int **array, int perline, int max);
void			plotLine(t_env *env, int x0, int y0, int z0, int x1, int y1, int z1);
void			bresenham(t_env *env, int x0, int y0, int x1, int y1);
void            set_color(t_env *env, int x, int y, int z);

#endif
