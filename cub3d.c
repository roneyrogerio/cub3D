/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:51:48 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/31 00:19:15 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "engine/vars.c"
#include "engine/frame.c"
#include "engine/rgb_utils.c"
#include "engine/mini_map.c"
#include "engine/key_event.c"
#include "engine/quit.c"

void	mlx_pixel_put_image(void *img, int x, int y, int color)
{
	char	*dst;
	int		bpp;
	int		size_line;
	int		endian;

	dst = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	dst += y * size_line + x * (bpp / 8);
	*(unsigned int*)dst = rgb_alpha(*(unsigned int*)dst, color);
}

double	rand_double(void)
{
	return (rand() / (double)RAND_MAX);
}

int		rand_int(int a, int b)
{
	return ((int)((b - a + 1) * rand_double()) + a);
}

void	raycast(t_vars *core)
{
	int i;
	int j;

	i = 0;
	while (i < core->ht)
	{
		j = 0;
		while (j < core->wd)
		{
			if (rand_int(0, 1))
				mlx_pixel_put_image(core->img, j, i, 0xFFffffff);
			else
				mlx_pixel_put_image(core->img, j, i, 0xFF181a18);
			j++;
		}
		i++;
	}
}

int		main(void)
{
	t_vars	*vars;

	vars = my_vars();
	vars_setup(vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->wd, vars->ht, "cub3D");
	vars->img = mlx_new_image(vars->mlx, vars->wd, vars->ht);
	mlx_loop_hook(vars->mlx, frame, vars);
	mlx_key_hook(vars->win, key_event, vars);
	//mlx_hook(vars->win, 0, 1L<<5, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
