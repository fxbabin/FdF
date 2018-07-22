/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:59:08 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/22 19:33:01 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_env_2(t_env *env, int bpp, int size_line, int endian)
{
	if (!(env->mlx_ptr = mlx_init()))
		ft_error();
	if (!(env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT,
			"FDF 42 FBABIN")))
		ft_error();
	if (!(env->mlx_img = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT)))
		ft_error();
	if (!(env->img = (unsigned int*)mlx_get_data_addr(env->mlx_img, &(bpp),
			&(size_line), &(endian))))
		ft_error();
}

t_env	*init_env(void)
{
	t_env	*env;
	int		bpp;
	int		size_line;
	int		endian;

	bpp = 32;
	size_line = WIDTH * 4;
	endian = 1;
	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		ft_error();
	env->base_width = BASE_WIDTH;
	env->base_height = BASE_HEIGHT;
	env->rot_x = 1.0;
	env->rot_y = 0.7;
	env->rot_z = -0.4;
	env->base_z = 1;
	env->weird = 0;
	init_env_2(env, bpp, size_line, endian);
	return (env);
}

int		check_file_opening(t_env *env, int argc, char **argv)
{
	if (argc < 2)
		return (-1);
	env->fd = open(argv[1], O_RDONLY);
	if (env->fd == -1)
	{
		ft_dprintf(2, "%+kError :%k open() failed%k\n", LRED, EOC, RESET);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_env		*env;

	if (argc < 2)
	{
		ft_dprintf(2, "%+kError :%k no input file given%k\n", LRED, EOC, RESET);
		return (0);
	}
	if (!(env = init_env()))
		return (-1);
	if (!env || !check_file_opening(env, argc, argv))
		return (-1);
	if (!get_coords(env))
		return (-1);
	if ((close(env->fd)) == -1)
		exit(ft_dprintf(2, "%+kError :%k close() failed%k\n", LRED,
			EOC, RESET));
	mlx_hook(env->win_ptr, 2, 1L << 0, deal_key, env);
	if (env->weird)
		weird_display_grid(env);
	else
		display_grid(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	mlx_loop(env->mlx_ptr);
	return (0);
}
