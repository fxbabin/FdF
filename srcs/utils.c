/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 01:50:00 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/22 21:44:49 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		is_number(char *str)
{
	int		i;

	i = -1;
	if (!str || !*str)
	{
		ft_dprintf(2, "%+kError :%k invalid map%k\n", LRED, EOC, RESET);
		exit(-1);
	}
	if (str[0] == '-')
		i++;
	if (str[i + 1] && str[i + 1] < '0' && str[i + 1] > '9')
		return (0);
	while (str[++i] && str[i] != ',')
	{
		if (str[i] > '9' || str[i] < '0')
		{
			ft_dprintf(2, "%+kError :%k invalid map%k\n", LRED, EOC, RESET);
			exit(-1);
		}
	}
	return (1);
}

int		ft_max(int nb1, int nb2)
{
	return (nb1 > nb2 ? nb1 : nb2);
}

double	ft_absdouble(double nb)
{
	return ((nb < 0.0) ? -nb : nb);
}

void	ft_error(void)
{
	ft_dprintf(2, "%+kError :%k malloc failed%k\n", LRED, EOC, RESET);
	exit(-1);
}
