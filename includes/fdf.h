/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:59:18 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/22 21:47:31 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** --------------------------------- INCLUDES -------------------------------
*/

# include "mlx.h"
# include "ft_printf.h"
# include "io.h"
# include "lst.h"
# include "array.h"
# include "math.h"

# define WIDTH 1380
# define HEIGHT 1380
# define BASE_WIDTH 400
# define BASE_HEIGHT 400

# define K_EXIT 53
# define K_4 86
# define K_5 87
# define K_6 88
# define K_7 89
# define K_8 91
# define K_9 92
# define K_W 13
# define K_ARROW_UP 123
# define K_ARROW_DOWN 124
# define K_ARROW_LEFT 126
# define K_ARROW_RIGHT 125
# define K_ARROW_MINUS 78
# define K_ARROW_PLUS 69

/*
** -------------------------------- STRUCTURES -------------------------------
*/

typedef struct		s_dot
{
	int				x;
	int				y;
	int				z;
}					t_dot;

typedef struct		s_coord
{
	double			x;
	double			y;
	double			z;
}					t_coord;

typedef struct		s_bres
{
	int				dx;
	int				dy;
	float			m;
	int				adjust;
	float			offset;
	float			threshold;
	float			delta;
	int				x;
	int				y;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
}					t_bres;

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
	int				weird;
}					t_env;

/*
** ----------------------------------------------------------------------------
** ---------------------------------- SOURCES ---------------------------------
** ----------------------------------------------------------------------------
*/

int					get_coords(t_env *env);
void				ft_int22dump(int **array, int perline, int max);
void				bresenham(t_env *env, t_dot *d0, t_dot *d1);
void				set_color(t_env *env, int x, int y, int z);
int					deal_key(int key, void *param);
void				display_grid(t_env *env);
void				weird_display_grid(t_env *env);
void				rotate(t_env *env, t_dot *d, int i);
void				weird_rotate(t_env *env, t_dot *d, int i);
int					ft_max(int nb1, int nb2);
double				ft_absdouble(double nb);
void				ft_error(void);
int					is_number(char *str);

#endif
