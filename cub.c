/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 17:51:48 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/29 22:40:41 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "core.c"
#include "frame.c"
#include "rgb.c"
#include "map.c"
#include "key_event.c"
#include "quit.c"

void	mlx_pixel_put_image(void *img, int x, int y, int color, double alpha)
{
	char	*dst;
	int		bpp;
	int		size_line;
	int		endian;

	dst = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	dst += y * size_line + x * (bpp / 8);
	*(unsigned int*)dst = rgb_sum(*(unsigned int*)dst, color, alpha);
}

double	rand_double(void)
{
	return (rand() / (double)RAND_MAX);
}

int		rand_int(int a, int b)
{
	return ((int)((b - a + 1) * rand_double()) + a);
}

void	raycast(t_core *core)
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
				mlx_pixel_put_image(core->img, j, i, 0xffffff, 0.5);
			else
				mlx_pixel_put_image(core->img, j, i, 0x181a18, 0.5);
			j++;
		}
		i++;
	}
}

int		main()
{
	t_core	*core;

	core = mcore();
	core_init(core);
	core->mlx = mlx_init();
	core->win = mlx_new_window(core->mlx, core->wd, core->ht, "cub3D");
	core->img = mlx_new_image(core->mlx, core->wd, core->ht);
	mlx_loop_hook(core->mlx, frame, core);
	mlx_key_hook(core->win, key_event, core);
	//mlx_hook(core->win, 0, 1L<<5, quit, core);
	mlx_loop(core->mlx);
	return (0);
}
