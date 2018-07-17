/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 23:51:47 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/17 02:20:39 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			set_1(t_env *env, t_dot *d0, t_dot *d1, int i)
{
	d0->x = *(env->x[i]);
	d0->y = *(env->y[i]);
	d0->z = *(env->coords[i]);
	d1->x = *(env->x[i + env->nb_col]);
	d1->y = *(env->y[i + env->nb_col]);
	d1->z = *(env->coords[i + env->nb_col]);
	return (1);
}

int			set_2(t_env *env, t_dot *d0, t_dot *d1, int i)
{
	d0->x = *(env->x[i]);
	d0->y = *(env->y[i]);
	d0->z = *(env->coords[i]);
	d1->x = *(env->x[i + 1]);
	d1->y = *(env->y[i + 1]);
	d1->z = *(env->coords[i + 1]);
	return (1);
}

void		disp(t_env *env)
{
	int		i;
	int		lign;
	t_dot	d0;
	t_dot	d1;

	i = -1;
	lign = 1;
	while (env->coords[++i + 1])
	{
		if (((i + 1) % env->nb_col) == 0)
		{
			if (lign < env->nb_lign && set_1(env, &d0, &d1, i))
				bresenham(env, &d0, &d1);
			lign++;
		}
		else
		{
			set_2(env, &d0, &d1, i);
			bresenham(env, &d0, &d1);
			if (lign < env->nb_lign && set_1(env, &d0, &d1, i))
				bresenham(env, &d0, &d1);
		}
	}
}

void		weird_display_grid(t_env *env)
{
	t_dot		d;
	int			i;
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
			d.x = env->base_width;
			d.y += env->net_size;
			lign++;
		}
		else
			d.x += env->net_size;
	}
	disp(env);
}

void		display_grid(t_env *env)
{
	t_dot		d;
	int			i;
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
			d.x = env->base_width;
			d.y += env->net_size;
			lign++;
		}
		else
			d.x += env->net_size;
	}
	disp(env);
}
