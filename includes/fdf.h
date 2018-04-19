/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:59:18 by fbabin            #+#    #+#             */
/*   Updated: 2018/04/19 16:06:04 by fbabin           ###   ########.fr       */
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

# define WIDTH 1920
# define HEIGHT 1380

/*
 ** -------------------------------- STRUCTURES -------------------------------
 */

typedef struct		s_env
{
	int				**coords;
	int				fd;
	int				b_x;
	int				b_y;
	int				screen_x;
	int				screen_y;
	int				s_x;
	int				s_y;
	int				x;
	int				y;
	int				scale;
	void			*mlx_ptr;
	void			*win_ptr;
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

#endif
