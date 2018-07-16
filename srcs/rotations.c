/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 23:50:37 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/16 20:56:08 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotate_x(t_env *env, t_coord *dot_t, t_coord *dot_r)
{
	dot_r->x = dot_t->x;
	dot_r->y = (dot_t->y * cos(env->rot_x)) - (dot_t->z * sin(env->rot_x));
	dot_r->z = (dot_t->y * sin(env->rot_x)) + (dot_t->z * cos(env->rot_x));
}

void			rotate_y(t_env *env, t_coord *dot_t, t_coord *dot_r)
{
	dot_t->x = dot_r->x;
	dot_t->y = dot_r->y;
	dot_t->z = dot_r->z;
	dot_r->x = (dot_t->x * cos(env->rot_y)) + (dot_t->z * sin(env->rot_y));
	dot_r->y = dot_t->y;
	dot_r->z = -(dot_t->x * sin(env->rot_y)) + (dot_t->z * cos(env->rot_y));
}

void			rotate_z(t_env *env, t_coord *dot_t, t_coord *dot_r)
{
	dot_t->x = dot_r->x;
	dot_t->y = dot_r->y;
	dot_t->z = dot_r->z;
	dot_r->x = (dot_t->x * cos(env->rot_z)) - (dot_t->y * sin(env->rot_z));
	dot_r->y = (dot_t->x * sin(env->rot_z)) + (dot_t->y * cos(env->rot_z));
	dot_r->z = dot_t->z;
}

void			rotate(t_env *env, t_dot *d, int i)
{
	t_coord		dot_t;
	t_coord		dot_r;
	t_dot		tmp;

	dot_t.x = d->x - env->x_center;
	dot_t.y = d->y - env->y_center;
	dot_t.z = d->z * env->base_z;
	rotate_x(env, &dot_t, &dot_r);
	rotate_y(env, &dot_t, &dot_r);
	rotate_z(env, &dot_t, &dot_r);
	tmp.x = dot_r.x + env->x_center;
	tmp.y = dot_r.y + env->y_center;
	tmp.z = dot_r.z;
	set_color(env, tmp.x, tmp.y, *(env->coords[i]));
	*(env->x[i]) = tmp.x;
	*(env->y[i]) = tmp.y;
	*(env->z[i]) = tmp.z;
}

void			weird_rotate(t_env *env, t_dot *d, int i)
{
	t_coord		dot_t;
	t_coord		dot_r;

	dot_t.x = d->x - env->x_center;
	dot_t.y = d->y - env->y_center;
	dot_t.z = d->z * env->base_z;
	rotate_x(env, &dot_t, &dot_r);
	rotate_y(env, &dot_t, &dot_r);
	rotate_z(env, &dot_t, &dot_r);
	d->x = dot_r.x + env->x_center;
	d->y = dot_r.y + env->y_center;
	d->z = dot_r.z;
	set_color(env, d->x, d->y, *(env->coords[i]));
	*(env->x[i]) = d->x;
	*(env->y[i]) = d->y;
	*(env->z[i]) = d->z;
}
