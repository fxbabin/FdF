/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotLine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 22:43:34 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/09 22:53:42 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		plotLineLow(t_env *env, int x0, int y0, int z0, int x1, int y1, int z1)
{
	double		dx;
	double		dy;
	int			yi;
	int			x;
	int			y;
	double		D;

	dx = x1 - x0;
	dy = y1 - y0;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	D = 2 * dy - dx;
	y = y0;
	x = x0;
	(void)z1;
	while (++x < x1)
	{
		set_color(env, x, y, (z0 > z1) ? z0: z1);
		//env->img[y * WIDTH + x] = 0xFFFFFF;
		if (D > 0)
		{
			y = y + yi;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}

void	plotLineHigh(t_env *env, int x0, int y0, int z0, int x1, int y1, int z1)
{
	double		dx;
	double		dy;
	int			xi;
	int			x;
	int			y;
	double		D;

	dx = x1 - x0;
	dy = y1 - y0;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	D = 2 * dx - dy;
	y = y0;
	x = x0;
	(void)z1;
	while (++y < y1)
	{
		set_color(env, x, y, (z0 > z1) ? z0: z1);
		//env->img[y * WIDTH + x] = 0xFFFFFF;
		if (D > 0)
		{
			x = x + xi;
			D = D - 2 * dy;
		}
		D = D + 2 * dx;
	}
}

void	plotLine(t_env *env, int x0, int y0, int z0, int x1, int y1, int z1)
{
	if (ft_abs(y1 - y0) < ft_abs(x1 - x0))
	{
		if (x0 > x1)
			plotLineLow(env, x1, y1, z1, x0, y0, z0);
		else
			plotLineLow(env, x0, y0, z0, x1, y1, z1);
	}
	else
	{
		if (y0 > y1)
			plotLineHigh(env, x1, y1, z1, x0, y0, z0);
		else
			plotLineHigh(env, x0, y0, z0, x1, y1, z1);
	}
}
