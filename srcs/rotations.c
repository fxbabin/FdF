/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 23:50:37 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/11 00:32:43 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			rotate(t_env *env, int x, int y, int z, int i)
{
	t_coord		dot_t;
	t_coord		dot_r;

	//rotate x
	dot_t.x = x - env->x_center;
	dot_t.y = y - env->y_center;
	dot_t.z = z * env->base_z;
	dot_r.x = dot_t.x;
	dot_r.y = (dot_t.y * cos(env->rot_x)) - (dot_t.z * sin(env->rot_x));
	dot_r.z = (dot_t.y * sin(env->rot_x)) + (dot_t.z * cos(env->rot_x));

	//rotate y
	dot_t.x = dot_r.x;
	dot_t.y = dot_r.y;
	dot_t.z = dot_r.z;
	dot_r.x = (dot_t.x * cos(env->rot_y)) + (dot_t.z * sin(env->rot_y));
	dot_r.y = dot_t.y;
	dot_r.z = -(dot_t.x * sin(env->rot_y)) + (dot_t.z * cos(env->rot_y));
	
	//rotate z
	dot_t.x = dot_r.x;
	dot_t.y = dot_r.y;
	dot_t.z = dot_r.z;
	dot_r.x = (dot_t.x * cos(env->rot_z)) - (dot_t.y * sin(env->rot_z));
	dot_r.y = (dot_t.x * sin(env->rot_z)) + (dot_t.y * cos(env->rot_z));
	dot_r.z = dot_t.z;

	x = dot_r.x + env->x_center;
	y = dot_r.y + env->y_center;
	z = dot_r.z;
	set_color(env, x, y, *(env->coords[i]));
	*(env->x[i]) = x;
	*(env->y[i]) = y;
	*(env->z[i]) = z;
}
