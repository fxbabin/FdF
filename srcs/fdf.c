/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbabin <fbabin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:59:08 by fbabin            #+#    #+#             */
/*   Updated: 2018/07/09 23:55:08 by fbabin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "math.h"

void		set_color(t_env *env, int x, int y, int z)
{
	int		tmp;

	tmp = z;
	if (z != 0)
	{
		tmp += env->base_z;
		if ((z < 0 && tmp > 0) || (z > 0 && tmp < 0))
			z = 0;
		//dot_t.z += (z < 0) ? -(env->base_z) : env->base_z;
	}
	if (z != 0)
	{
		z += (z < 0) ? -(env->base_z) : env->base_z;
		//ft_printf("%d\n", z);
	}
	if (z < 0 )
		env->img[(int)(y * WIDTH + x)] = 0x850A85;
	else if (z >= 0 && z < 5)
		env->img[(int)(y * WIDTH + x)] = 0x1860B6;
	else if (z >= 5 && z < 100)
		env->img[(int)(y * WIDTH + x)] = 0x0F7E17;
	else if (z >= 100 && z < 150)
		env->img[(int)(y * WIDTH + x)] = 0x792E0D;
	else
		env->img[(int)(y * WIDTH + x)] = 0xFFFFFF;
}

void		rotate(
		t_env *env, 
		int x, 
		int y, 
		int z,
		int i,
		int lign)
{
	t_coord		dot_t;
	t_coord		dot_r;

	//rotate x
	dot_t.x = x - env->x_center;
	dot_t.y = y - env->y_center;
	dot_t.z = z;
	if (z != 0)
	{
		dot_t.z += env->base_z;
		if ((z < 0 && dot_t.z > 0) || (z > 0 && dot_t.z < 0))
			dot_t.z = 0;
		//dot_t.z += (z < 0) ? -(env->base_z) : env->base_z;
	}
	dot_r.x = (dot_t.x * cos(env->rot_x)) - (dot_t.y * sin(env->rot_x));
	dot_r.y = (dot_t.x * sin(env->rot_x)) + (dot_t.y * cos(env->rot_x));
	dot_r.z = dot_t.z;
	x = dot_r.x + env->x_center;
	y = dot_r.y + env->y_center;
	z = dot_r.z;
	
	//rotate y
	dot_t.x = x - env->x_center;
	dot_t.y = y - env->y_center;
	dot_t.z = z;
	dot_r.x = (dot_t.x * cos(env->rot_y)) + (dot_t.z * sin(env->rot_y));
	dot_r.y = dot_t.y;
	dot_r.z = -(dot_t.x * sin(env->rot_y)) + (dot_t.z * cos(env->rot_y));
	x = dot_r.x + env->x_center;
	y = dot_r.y + env->y_center; 
	z = dot_r.z;

	//rotate z
	dot_t.x = x - env->x_center;
	dot_t.y = y - env->y_center;
	dot_t.z = z;
	dot_r.x = dot_t.x;
	dot_r.y = (dot_t.y * cos(env->rot_z)) - (dot_t.z * sin(env->rot_z));
	dot_r.z = (dot_t.y * sin(env->rot_z)) + (dot_t.z * cos(env->rot_z));
	x = dot_r.x + env->x_center;
	y = dot_r.y + env->y_center;
	z = dot_r.z;
	
	set_color(env, x, y, *(env->coords[i]));
	*(env->x[i]) = x;
	*(env->y[i]) = y;
	*(env->z[i]) = z;
	(void)i;
	(void)lign;
	/*if (((i + 1) % env->nb_col) == 0)
	{
		if (lign  < env->nb_lign)
			plotLine(env, x, y, x, y + env->net_size);
	}
	else
	{
		plotLine(env, x, y, x + env->net_size, y);
		if (lign < env->nb_lign)
			plotLine(env, x, y, x, y + env->net_size);
	}*/

}
void	disp(t_env *env)
{
	int		i;
	int		lign;

	i = -1;
	lign = 1;
	while (env->coords[++i + 1])
	{
		
		//rotate_x(env, x, y, *(env->coords[i]));
		//rotate(env, x, y, *(env->coords[i]), i, lign);
		//rotate_y(env, x, y, *(env->coords[i]));
		//env->img[(int)(y * WIDTH + x)] = 0xFFFFFF;
		//set_color(env, *(env->coords[i]), x , y);
		//env->img[y * WIDTH + x] = 0xFFFFFF;
		
		if (((i + 1) % env->nb_col) == 0)
		{
			if (lign  < env->nb_lign)
				plotLine(env, *(env->x[i]), *(env->y[i]), *(env->coords[i]), *(env->x[i+env->nb_col]), *(env->y[i+env->nb_col]), *(env->coords[i+env->nb_col]));
			//plotLine(env, *(env->x[i]), *(env->y[i]), *(env->x[i+1]), *(env->y[i]));
			lign++;
		}
		else
		{
			plotLine(env, *(env->x[i]), *(env->y[i]), *(env->coords[i]), *(env->x[i+1]), *(env->y[i+1]), *(env->coords[i+1]));
			//bresenham(env, *(env->x[i]), *(env->y[i]), *(env->x[i]), *(env->y[i+1]));
			//plotLine(env, x, y, x + env->net_size, y);
			if (lign < env->nb_lign)
				plotLine(env, *(env->x[i]), *(env->y[i]), *(env->coords[i]), *(env->x[i+env->nb_col]), *(env->y[i+env->nb_col]), *(env->coords[i+env->nb_col]));
			//	plotLine(env, x, y, x, y + env->net_size);
		}
	}
}

void	display_grid(t_env *env)
{
	int		i;
	double	x;
	double	y;
	int		lign;

	i = -1;
	lign = 1;
	x = env->base_width;
	y = env->base_height;
	while (env->coords[++i + 1])
	{
		
		//rotate_x(env, x, y, *(env->coords[i]));
		rotate(env, x, y, *(env->coords[i]), i, lign);
		//rotate_y(env, x, y, *(env->coords[i]));
		//env->img[(int)(y * WIDTH + x)] = 0xFFFFFF;
		//set_color(env, *(env->coords[i]), x , y);
		//env->img[y * WIDTH + x] = 0xFFFFFF;
		
		if (((i + 1) % env->nb_col) == 0)
		{
			//if (lign  < env->nb_lign)
			//	plotLine(env, x, y, x, y + env->net_size);
			x = env->base_width;
			y += env->net_size;
			lign++;
		}
		else
		{
			//plotLine(env, x, y, x + env->net_size, y);
			//if (lign < env->nb_lign)
			//	plotLine(env, x, y, x, y + env->net_size);
			x += env->net_size;
		}
	}
	disp(env);
}
int				deal_key(int key, void *param)
{
	t_env		*env;

	env = (t_env*)param;
	ft_printf("%d\n", key);
	if (key == 53)
	{
		ft_printf("EXIT VISUALISOR\n");
		exit(0);
	}
	if (key == 92)
	{
		env->rot_x += 0.1;
		ft_printf("%f\n", env->rot_x);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == 89)
	{
		env->rot_x -= 0.1;
		ft_printf("%f\n", env->rot_x);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == 88)
	{
		env->rot_y += 0.1;
		ft_printf("%f\n", env->rot_y);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == 86)
	{
		env->rot_y -= 0.1;
		ft_printf("%f\n", env->rot_y);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == 91)
	{
		env->rot_z += 0.1;
		ft_printf("%f\n", env->rot_z);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == 87)
	{
		env->rot_z -= 0.1;
		ft_printf("%f\n", env->rot_y);
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == 123)
	{
		env->base_width -= 10;
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == 124)
	{
		env->base_width += 10;
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == 126)
	{
		env->base_height -= 10;
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == 125)
	{
		env->base_height += 10;
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == 78)
	{
		env->base_z -= 5;
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
	}
	if (key == 69)
	{
		env->base_z += 5;
		ft_bzero(env->img, WIDTH * HEIGHT * 4);
		display_grid(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->mlx_img, 0, 0);
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
	if (!(env = (t_env*)ft_memalloc(sizeof(t_env))))
		return (0);
//if (!(env->dots = (t_coord**)ft_memalloc(sizeof(t_coord*))))
	//	return (0);
	env->base_width = BASE_WIDTH;
	env->base_height = BASE_HEIGHT;
	env->rot_x = 0.8;
	env->rot_z = 1.1;
	env->base_z = 0;
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
