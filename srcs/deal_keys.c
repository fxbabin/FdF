/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 23:54:02 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/17 02:23:11 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		display_changes(t_env *env)
{
	ft_printf("x : %f y: %f z: %f\n", env->rot_x, env->rot_y, env->rot_z);
	ft_bzero(env->img, WIDTH * HEIGHT * 4);
	if (env->weird)
		weird_display_grid(env);
	else
		display_grid(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
}

int			deal_key_2(t_env *env, int key)
{
	if (key == K_ARROW_UP && (env->base_width -= 10))
		display_changes(env);
	if (key == K_ARROW_DOWN && (env->base_width += 10))
		display_changes(env);
	if (key == K_ARROW_LEFT && (env->base_height -= 10))
		display_changes(env);
	if (key == K_ARROW_RIGHT && (env->base_height += 10))
		display_changes(env);
	if (key == K_ARROW_MINUS && (env->base_z -= 1))
		display_changes(env);
	if (key == K_ARROW_PLUS && (env->base_z += 1))
		display_changes(env);
	if (key == K_W)
	{
		env->weird = (env->weird == 1) ? 0 : 1;
		display_changes(env);
	}
	return (0);
}

int			deal_key(int key, void *param)
{
	t_env		*env;

	env = (t_env*)param;
	if (key == K_EXIT)
	{
		ft_printf("EXIT VISUALISOR\n");
		exit(0);
	}
	if (key == K_9 && (env->rot_z += 0.1))
		display_changes(env);
	if (key == K_7 && (env->rot_z -= 0.1))
		display_changes(env);
	if (key == K_6 && (env->rot_y += 0.1))
		display_changes(env);
	if (key == K_4 && (env->rot_y -= 0.1))
		display_changes(env);
	if (key == K_8 && (env->rot_x += 0.1))
		display_changes(env);
	if (key == K_5 && (env->rot_x -= 0.1))
		display_changes(env);
	return (deal_key_2(env, key));
}
