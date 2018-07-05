/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:59:08 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/04 21:09:05 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				deal_key(int key, void *param)
{
	t_env		*env;

	env = (t_env*)param;
	if (key == 53)
	{
		ft_printf("EXIT VISUALISOR\n");
		exit(0);
	}
	return (0);
}

t_env	*init_env()
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	env->b_x = 200;
	env->b_y = 200;
	env->screen_x = WIDTH;
	env->screen_y = HEIGHT;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->screen_x, env->screen_y,
			"FDF 42 FBABIN");
	return (env);
}

int		check_file_opening(t_env *env, int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	env->fd = open(argv[1], O_RDONLY);
	if (env->fd == -1)
	{
		ft_printf("open() failed\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_env		*env;

	env = init_env();
	if (!env || !check_file_opening(env, argc, argv))
		return (-1);
	if (!get_coords(env))
		return (-1);
	//mlx_key_hook(env->win_ptr, deal_key, env);
	//mlx_loop(env->mlx_ptr);
	return (0);
}
