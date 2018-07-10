/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 23:54:02 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/11 00:45:40 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			deal_key(int key, void *param)
{
	t_env		*env;

	env = (t_env*)param;
	ft_printf("%d\n", key);
	if (key == K_EXIT)
	{
		ft_printf("EXIT VISUALISOR\n");
		exit(0);
	}
	//Z Rotation
	if (key == K_9)
	{
		env->rot_z += 0.1;
		ft_printf("x : %f y: %f z: %f\n", env->rot_x, env->rot_y, env->rot_z);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == K_7)
	{
		env->rot_z -= 0.1;
		ft_printf("x : %f y: %f z: %f\n", env->rot_x, env->rot_y, env->rot_z);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}

	if (key == K_6)
	{
		env->rot_y += 0.1;
		ft_printf("x : %f y: %f z: %f\n", env->rot_x, env->rot_y, env->rot_z);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == K_4)
	{
		env->rot_y -= 0.1;
		ft_printf("x : %f y: %f z: %f\n", env->rot_x, env->rot_y, env->rot_z);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == K_8)
	{
		env->rot_x += 0.1;
		ft_printf("x : %f y: %f z: %f\n", env->rot_x, env->rot_y, env->rot_z);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == K_5)
	{
		env->rot_x -= 0.1;
		ft_printf("x : %f y: %f z: %f\n", env->rot_x, env->rot_y, env->rot_z);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == K_ARROW_UP)
	{
		env->base_width -= 10;
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == K_ARROW_DOWN)
	{
		env->base_width += 10;
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == K_ARROW_LEFT)
	{
		env->base_height -= 10;
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == K_ARROW_RIGHT)
	{
		env->base_height += 10;
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == K_ARROW_MINUS)
	{
		env->base_z -= 1;
		ft_printf("%d\n", env->base_z);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == K_ARROW_PLUS)
	{
		env->base_z += 1;
		ft_printf("%d\n", env->base_z);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	return (0);
}
