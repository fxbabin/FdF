/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 18:52:44 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/17 01:51:29 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_bresenham(t_bres *b, t_dot *d0, t_dot *d1)
{
	b->x1 = d0->x;
	b->x2 = d1->x;
	b->y1 = d0->y;
	b->y2 = d1->y;
	b->z1 = d0->z;
	b->z2 = d1->z;
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
		b->offset += b->delta;
		if (b->offset >= b->threshold)
		{
			b->y += b->adjust;
			b->threshold += 1;
		}
	}
}

void		bresenham(t_env *env, t_dot *d0, t_dot *d1)
{
	t_bres			b;

	init_bresenham(&b, d0, d1);
	if (b.dx == 0)
	{
		if (b.y2 < b.y1)
			ft_swap(&b.y2, &b.y1);
		b.y = b.y1 - 1;
		while (++(b.y) <= b.y2)
			set_color(env, b.x1, b.y, ft_max(d0->z, d1->z));
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
