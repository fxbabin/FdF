/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2dump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:30:41 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/18 20:32:36 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "utils.h"
#include "ft_printf.h"

void			ft_dispfirst(int width, int nb_perline, int max)
{
	int		i;

	i = -1;
	ft_printf("%-*c| ", width - 1, ' ');
	ft_printf("%+k", LRED);
	while (++i < nb_perline)
	{
		if (i > max - 1 && i < nb_perline - max)
		{
			if (i == max)
				ft_printf("%-*s", width, "...");
		}
		else
			ft_printf("%-*d", width, i);
	}
	ft_printf("%k\n", RESET);
	i = width * (((nb_perline > (max * 2) + 2))
			? (max * 2) + 2 : nb_perline + 1);
	ft_printf("%k", RESET);
	while (i--)
		ft_printf("-");
	ft_printf("\n");
}

static int		ft_count(int nb)
{
	int		i;

	if (nb == 0)
		return (1);
	i = (nb < 0) ? 1 : 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int		get_maxwidth(int **array, int nb_perline)
{
	int		max;
	int		t;
	int		i;

	t = ft_tabsize((void**)array);
	max = ft_count(nb_perline);
	max = (ft_count(t / nb_perline) > max) ? ft_count(t / nb_perline) : max;
	i = -1;
	while (array[++i])
	{
		if ((ft_count(*array[i])) > max)
			max = ft_count(*array[i]);
	}
	return (max + 2);
}

static void		disp_line(int **array, int curr_line, int nb_perline, int max)
{
	int		i;
	int		m;
	int		width;

	width = get_maxwidth(array, nb_perline);
	i = (curr_line * nb_perline) - 1;
	m = i + nb_perline;
	while (++i <= m && array[i])
	{
		if (i % nb_perline > max - 1 && i % nb_perline < nb_perline - max)
		{
			if (i % nb_perline == max)
				ft_printf("%-*s", width, "...");
		}
		else
			ft_printf("%-*d", width, *array[i]);
	}
	ft_printf("\n");
}

void			ft_int2dump(int **array, int nb_perline, int max)
{
	int		curr_line;
	int		max_line;
	int		width;

	curr_line = 0;
	width = get_maxwidth(array, nb_perline);
	max_line = (ft_tabsize((void**)array) / nb_perline);
	if (!array || !*array)
		return ;
	ft_dispfirst(width, nb_perline, max);
	while (curr_line < max_line)
	{
		if (curr_line == max && max <= max_line / 2)
		{
			ft_printf("%-*s| %*s\n", width - 1, "...",
				(width) * (max + 1) - 2, "...");
			curr_line += max_line - (2 * max);
		}
		ft_printf("%+k%-*d%k| ", LBLUE, width - 1, curr_line, RESET);
		disp_line(array, curr_line, nb_perline, max);
		curr_line++;
	}
}
