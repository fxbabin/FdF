/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 23:51:47 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/16 17:56:43 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		disp(t_env *env)
{
	int		i;
	int		lign;

	i = -1;
	lign = 1;
	while (env->coords[++i + 1])
	{

		/*rotate_x(env, x, y, *(env->coords[i]));
		  rotate(env, x, y, *(env->coords[i]), i, lign);
		  rotate_y(env, x, y, *(env->coords[i]));
		  env->img[(int)(y * WIDTH + x)] = 0xFFFFFF;
		  set_color(env, *(env->coords[i]), x , y);
		  env->img[y * WIDTH + x] = 0xFFFFFF;*/

		if (((i + 1) % env->nb_col) == 0)
		{
			if (lign  < env->nb_lign)
				bresenham(env, *(env->x[i]), *(env->y[i]), *(env->coords[i]), *(env->x[i+env->nb_col]), *(env->y[i+env->nb_col]), *(env->coords[i+env->nb_col]));
			lign++;
		}
		else
		{
			bresenham(env, *(env->x[i]), *(env->y[i]), *(env->coords[i]), *(env->x[i+1]), *(env->y[i+1]), *(env->coords[i+1]));
			if (lign < env->nb_lign)
				bresenham(env, *(env->x[i]), *(env->y[i]), *(env->coords[i]), *(env->x[i+env->nb_col]), *(env->y[i+env->nb_col]), *(env->coords[i+env->nb_col]));
		}
	}
}

void	display_grid(t_env *env)
{
	t_dot		d;
	int			i;
	//double		x;
	//double		y;
	int			lign;

	i = -1;
	lign = 1;
	d.x = env->base_width;
	d.y = env->base_height;
	while (env->coords[++i + 1])
	{
		d.z = *(env->coords[i]);
		rotate(env, &d, i);
		if (((i + 1) % env->nb_col) == 0)
		{
			//if (lign  < env->nb_lign)
			//      plotLine(env, x, y, x, y + env->net_size);
			d.x = env->base_width;
			d.y += env->net_size;
			lign++;
		}
		else
		{
			//plotLine(env, x, y, x + env->net_size, y);
			//if (lign < env->nb_lign)
			//      plotLine(env, x, y, x, y + env->net_size);
			d.x += env->net_size;
		}
	}
	disp(env);
}

/*void    weird_display_grid(t_env *env)
{
	t_coord		d;
	int			i;
	//double		x;
	//double		y;
	int			lign;

	i = -1;
	lign = 1;
	d.x = env->base_width;
	d.y = env->base_height;
	while (env->coords[++i + 1])
	{
		d.z = *(env->coords[i]);
		weird_rotate(env, &d, i);
		if (((i + 1) % env->nb_col) == 0)
		{
			//if (lign  < env->nb_lign)
			//      plotLine(env, x, y, x, y + env->net_size);
			d.x = env->base_width;
			d.y += env->net_size;
			lign++;
		}
		else
		{
			//plotLine(env, x, y, x + env->net_size, y);
			//if (lign < env->nb_lign)
			//      plotLine(env, x, y, x, y + env->net_size);
			d.x += env->net_size;
		}
	}
	disp(env);
}*/
