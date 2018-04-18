/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:41:31 by fbabin            #+#    #+#             */
/*   Updated: 2018/04/18 23:51:26 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_in(char c, char *charset)
{
	int     i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

static int		ft_wordnb(char *str, char *charset)
{
	int     w;
	int     i;

	w = 0;
	i = -1;
	while (str[++i])
		if ((ft_in(str[i], charset) == 0) && ((ft_in(str[i + 1], charset) == 1)
					|| str[i + 1] == '\0'))
			w++;
	return (w);
}

int				check_line(char *str, int nbwords)
{
	if (!str)
		return (-1);
	if (ft_wordnb(str, " \t") != nbwords)
		return (-1);
	/*if (ft_charinset(',', str))
	{
		if (!ft_charins
	}*/
	return (0);
}

void			get_coords(t_env *env)
{
	t_list	*tmp;
	char	*line;
	int		nb_words;

	(void)env;
	tmp = NULL;
	if (sget_next_line(env->fd, &line) > 0)
	{
		ft_lstpushback(&tmp, ft_strdup(line), 0);
		nb_words = ft_wordnb(line, " \t");
		ft_strdel(&line);

	}
	ft_strdel(&line);
	while (sget_next_line(env->fd, &line) > 0)
	{
		//check_line();

		ft_lstpushback(&tmp, ft_strdup(line), 0);
		ft_printf("%s\n", line);
		ft_strdel(&line);
	}
	ft_lstdump(&tmp);
	ft_strdel(&line);

}
