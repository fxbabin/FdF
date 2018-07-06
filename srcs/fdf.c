/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:59:08 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/07 01:51:42 by fbabin           ###   ########.fr       */
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
	int		bpp;
	int		size_line;
	int		endian;

	bpp = 32;
	size_line = WIDTH * 4;
	endian = 1;
	if (!(env = (t_env*)malloc(sizeof(t_env))))
		return (0);
	env->base_width = 100;
	env->base_height = 100;
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

static void	set_color(t_env *env, int val, int x, int y)
{
	if (val > 0)
		env->img[y * WIDTH + x] = 0xFF0000;
	else
		env->img[y * WIDTH + x] = 0xFFFFFF;
}

void	display_grid(t_env *env)
{
	int		i;
	int		x;
	int		y;
	int		lign;

	i = -1;
	lign = 1;
	x = env->base_width;
	y = env->base_height;
	while (env->coords[++i + 1])
	{
		set_color(env, *(env->coords[i]), x, y);
		//env->img[y * WIDTH + x] = 0xFFFFFF;
		
		if (((i + 1) % env->nb_col) == 0)
		{
			if (lign  < env->nb_lign)
				plotLine(env, x, y, x, y + env->net_size);
			x = env->base_width;
			y += env->net_size;
			lign++;
		}
		else
		{
			plotLine(env, x, y, x + env->net_size, y);
			if (lign < env->nb_lign)
				plotLine(env, x, y, x, y + env->net_size);
			x += env->net_size;
		}
	}
}

int		main(int argc, char **argv)
{
	t_env		*env;

	env = init_env();
	if (!env || !check_file_opening(env, argc, argv))
		return (-1);
	if (!get_coords(env))
		return (-1);
	//ft_printf("%d\n", env->net_size);
	mlx_key_hook(env->win_ptr, deal_key, env);
	//env->img[100] = 0xFFFFFF;
	display_grid(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	mlx_loop(env->mlx_ptr);
	return (0);
}
