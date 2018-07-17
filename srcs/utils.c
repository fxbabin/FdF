/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 01:50:00 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/17 22:50:05 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
