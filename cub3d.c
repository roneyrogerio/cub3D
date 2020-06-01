/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:51:48 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/31 23:26:28 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				frame_pixel_draw(core->frame, j, i, 0xFFffffff);
			else
				frame_pixel_draw(core->frame, j, i, 0x80181a18);
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
	vars->frame = mlx_new_image(vars->mlx, vars->wd, vars->ht);
	mlx_loop_hook(vars->mlx, frame_draw, vars);
	mlx_key_hook(vars->win, key_event, vars);
	//mlx_hook(vars->win, 0, 1L<<5, quit, vars);
	mlx_loop(vars->mlx);
	return (0);
}
