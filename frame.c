/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:04:24 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/07 00:07:44 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		frame(t_vars *vars)
{
	//raycast(vars);
	eng_mini_map(vars->eng, &draw);
	mlx_put_image_to_window(
			vars->glib.mlx, vars->glib.win, vars->glib.frame, 0, 0);
	return (0);
}

void	pixel_draw(void *img, int x, int y, int color)
{
	char	*dst;
	int		bpp;
	int		size_line;
	int		endian;

	dst = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	dst += y * size_line + x * (bpp / 8);
	*(unsigned int*)dst = rgb_alpha(*(unsigned int*)dst, color);
}

void	draw(int x, int y, int color)
{
	pixel_draw((get_vars())->glib.frame, x, y, color);
}
