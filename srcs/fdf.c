/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:59:08 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/11 00:56:22 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env	*init_env()
{
	t_env	*env;
	int		bpp;
	int		size_line;
	int		endian;

	bpp = 32;
	size_line = WIDTH * 4;
	endian = 1;
	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		return (0);
//if (!(env->dots = (t_coord**)ft_memalloc(sizeof(t_coord*))))
	//	return (0);
	env->base_width = BASE_WIDTH;
	env->base_height = BASE_HEIGHT;
	env->rot_x = 1.0;
	env->rot_y = 0.7;
	env->rot_z = -0.4;
	env->base_z = 1;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT,
			"FDF 42 FBABIN");
	env->mlx_img = mlx_new_image(env->mlx_ptr, WIDTH, HEIGHT); 
	env->img = (unsigned int*)mlx_get_data_addr(env->mlx_img, &(bpp), &(size_line), &(endian));
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
	//env->rot_x = 0.0;
	//ft_printf("%d\n", env->net_size);
	mlx_key_hook(env->win_ptr, deal_key, env);
	//env->img[100] = 0xFFFFFF;
	display_grid(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	mlx_loop(env->mlx_ptr);
	return (0);
}
