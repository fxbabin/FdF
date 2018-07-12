/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 23:51:47 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/12 23:15:03 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		set_dot(t_env *env, int i)
{
	t_dot	d1;
	t_dot	d2;

	if (!env->coords[i + env->nb_col])
		return ;
	d1.x = *(env->x[i]);
	d1.y = *(env->y[i]);
	d1.z = *(env->coords[i]);
	d2.x = *(env->x[i + env->nb_col]);
	d2.y = *(env->y[i + env->nb_col]);
	d2.z = *(env->coords[i + env->nb_col]);
	env->d1 = &d1;
	env->d2 = &d2;
}

void		disp(t_env *env)
{
	int		i;
	int		lign;

	i = -1;
	lign = 1;
	while (env->coords[++i + 1])
	{
		set_dot(env, i);
		if (((i + 1) % env->nb_col) == 0)
		{
			if (lign < env->nb_lign)
				bresenham(env, env->d1, env->d2);
			lign++;
		}
		else
		{
			bresenham(env, env->d1, env->d2);
			if (lign < env->nb_lign)
				bresenham(env, env->d1, env->d2);
		}
	}
}

void		display_grid(t_env *env)
{
	int			i;
	double		x;
	double		y;
	int			lign;

	i = -1;
	lign = 1;
	x = env->base_width;
	y = env->base_height;
	while (env->coords[++i + 1])
	{
		rotate(env, x, y, *(env->coords[i]), i);
		if (((i + 1) % env->nb_col) == 0)
		{
			x = env->base_width;
			y += env->net_size;
			lign++;
		}
		else
		{
			x += env->net_size;
		}
	}
	disp(env);
}
