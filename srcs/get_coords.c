/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:41:31 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/08 01:09:06 by fbabin           ###   ########.fr       */
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

int			extract_coords(t_env *env, t_list *lst, int nb_words)
{
	char		**tmp;
	t_list		*l;
	int			y;
	int			i;

	l = lst;
	y = 0;
	(void)env;
	if (!(env->coords = ft_int2alloc(ft_lstsize(lst) * nb_words + 1, 1)))
		return (-1);
	while (lst)
	{
		if (!(tmp = ft_split(lst->content, " \t")))
			return (-1);
		i = -1;
		while (tmp[++i])
			*(env->coords[(y * nb_words) + i]) = ft_atoi(tmp[i]);
		y++;
		ft_free2((void**)tmp);
		lst = lst->next;
	}
	return (0);
}

void		set_net(t_env *env)
{
	if (env->nb_col >= env->nb_lign)
	{
		env->net_size = (WIDTH - (env->base_width * 2)) / (env->nb_col - 1);
		if (env->nb_col != env->nb_lign)
			env->base_height += ((env->nb_col - env->nb_lign) / 2) * env->net_size;
	}
	else
	{
		env->net_size = (HEIGHT - (env->base_height * 2)) / (env->nb_lign - 1);
		if (env->nb_col != env->nb_lign)
			env->base_width += ((env->nb_lign - env->nb_col) / 2) * env->net_size;
	}
	env->x_center = env->base_width + ((env->net_size * env->nb_col) / 2);
	env->y_center = env->base_height + ((env->net_size * env->nb_lign) / 2);
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
	ft_strdel(&line);
	env->nb_col = nb_words;
	env->nb_lign = ft_lstsize(tmp);
	set_net(env);
	extract_coords(env, tmp, nb_words);
	return (1);
}
