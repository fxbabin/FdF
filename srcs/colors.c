/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 23:48:35 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/10 23:50:23 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			set_color(t_env *env, int x, int y, int z)
{
	int			tmp;

	if ((int)(y * WIDTH + x) < 0 || (int)(y * WIDTH + x) > (WIDTH * HEIGHT))
		return ;
	/*if (z != 0)
	{
		tmp += env->base_z;
		if ((z < 0 && tmp > 0) || (z > 0 && tmp < 0))
			z = 0;
	}
	if (z != 0)
	{
		z += (z < 0) ? -(env->base_z) : env->base_z;
	}*/
	tmp = z * env->base_z;
	if ((z > 0 && tmp < 0) || (z < 0 && tmp > 0))
		z = 0;
	else
		z = tmp;
	if (z < 5)
		env->img[(int)(y * WIDTH + x)] = 0x1860B6;
	else if (z >= 5 && z < 100)
		env->img[(int)(y * WIDTH + x)] = 0x006600;
	else if (z >= 100 && z < 150)
		env->img[(int)(y * WIDTH + x)] = 0x792E0D;
	else
		env->img[(int)(y * WIDTH + x)] = 0xFFFFFF;
}
