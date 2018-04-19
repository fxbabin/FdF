/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:41:31 by fbabin            #+#    #+#             */
/*   Updated: 2018/04/19 17:25:44 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_is_word_nb(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!ft_charinset(str[i], "0123456789"))
			return (0);
	}
	return (1);
}

/*int				ft_is_word_nb(char *str, char *charset)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!ft_charinset(str[i], charset))
			return (0);
	}
	return (1);
}*/
static int		ft_wordnb(char *str, char *charset)
{
	int     w;
	int     i;

	w = 0;
	i = -1;
	while (str[++i])
		if ((ft_charinset(str[i], charset) == 0) && ((ft_charinset(str[i + 1], charset) == 1)
					|| str[i + 1] == '\0'))
			w++;
	return (w);
}

int			extract_coords(t_env *env, t_list *lst)
{
	char		**tmp;
	t_list		*l;

	l = lst;
	(void)env;
	while (lst)
	{
		if (!(tmp = ft_split()))
			return (-1);
		ft_printf("%s\n", lst->content);
		lst = lst->next;
	}
	return (0);
}

int			get_coords(t_env *env)
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
		if (ft_wordnb(line, " \t") != nb_words)
		{
			ft_strdel(&line);
			return (0);
		}
		ft_lstpushback(&tmp, ft_strdup(line), 0);
		ft_strdel(&line);
	}
	ft_lstdump(&tmp);
	ft_strdel(&line);
	extract_coords(env, tmp);
	return (1);
}
