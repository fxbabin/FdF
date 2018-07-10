/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:52:44 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/10 17:03:12 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_max(int nb1, int nb2)
{
		return (nb1 > nb2 ? nb1 : nb2);
}

double		ft_absdouble(double nb)
{
	return ((nb < 0.0) ? -nb : nb);
}

void		init_bresenham(t_bres *b, int x0, int y0, int z0, int x1, int y1, int z1)
{
	b->x1 = x0;
	b->x2 = x1;
	b->y1 = y0;
	b->y2 = y1;
	b->z1 = z0;
	b->z2 = z1;
	b->dx = b->x2 - b->x1;
	b->dy = b->y2 - b->y1;
}

void		bresenham_2(t_env *env, t_bres *b)
{
	b->delta = ft_absdouble((float)b->dx / (float)b->dy);
	b->x = b->x1;
	if (b->y2 < b->y1)
	{
		ft_swap(&b->y2, &b->y1);
		b->x = b->x2;
	}
	b->y = b->y1 - 1;
	while (++b->y <= b->y2)
	{
		set_color(env, b->x, b->y, ft_max(b->z1, b->z2));
		//env->img[b->y * WIDTH + b->x] = 0xFFFFFF;
		//mlx_pixel_put(env->mlx_ptr, env->win_ptr, b->x, b->y, 0xFFFFFF);
		b->offset += b->delta;
		if (b->offset >= b->threshold)
		{
			b->x += b->adjust;
			b->threshold += 1;
		}
	}
}

void		bresenham_1(t_env *env, t_bres *b)
{
	b->delta = ft_absdouble(b->m);
	b->y = b->y1;
	if (b->x2 < b->x1)
	{
		ft_swap(&(b->x2), &(b->x1));
		b->y = b->y2;
	}
	b->x = b->x1 - 1;
	while (++(b->x) <= b->x2)
	{
		set_color(env, b->x, b->y, ft_max(b->z1, b->z2));
		//env->img[b->y * WIDTH + b->x] = 0xFFFFFF;
		//mlx_pixel_put(env->mlx_ptr, env->win_ptr, b->x, b->y, 0xFFFFFF);
		b->offset += b->delta;
		if (b->offset >= b->threshold)
		{
			b->y += b->adjust;
			b->threshold += 1;
		}
	}
}

void		bresenham(t_env *env, int x0, int y0, int z0, int x1, int y1, int z1)
{
	t_bres			b;

	init_bresenham(&b, x0, y0, z0, x1, y1, z1);
	if (b.dx == 0)
	{
		if (b.y2 < b.y1)
			ft_swap(&b.y2, &b.y1);
		b.y = b.y1 - 1;
		while (++(b.y) <= b.y2)
			set_color(env, b.x1, b.y, ft_max(z0, z1));
			//env->img[b.y * WIDTH + b.x1] = 0xFFFFFF;
		//mlx_pixel_put(env->mlx_ptr, env->win_ptr, b.x1, b.y, 0xFFFFFF);
	}
	else
	{
		b.m = ((float)(b.dy) / (float)(b.dx));
		b.adjust = (b.m >= 0) ? 1 : -1;
		b.offset = 0.0;
		b.threshold = 0.5;
		if (b.m <= 1 && b.m >= -1)
			bresenham_1(env, &b);
		else
			bresenham_2(env, &b);
	}
}
