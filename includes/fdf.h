/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:59:18 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/07 00:22:02 by fbabin           ###   ########.fr       */
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

/*
 ** -------------------------------- STRUCTURES -------------------------------
 */

typedef struct		s_env
{
	int				**coords;
	int				fd;
	int				base_width;
	int				base_height;
	int				net_size;
	int				nb_col;
	int				nb_lign;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*mlx_img;
	unsigned int	*img;
}					t_env;

typedef struct		s_dot
{
	int				x;
	int				y;
	struct s_dot	*next;
}					t_dot;

/*
 ** ----------------------------------------------------------------------------
 ** ---------------------------------- SOURCES ---------------------------------
 ** ----------------------------------------------------------------------------
 */

int				get_coords(t_env *env);
void			ft_int22dump(int **array, int perline, int max);
void			plotLine(t_env *env, int x0, int y0, int x1, int y1);

#endif
