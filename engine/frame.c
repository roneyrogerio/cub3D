/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:04:24 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/31 23:24:03 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	frame_draw(t_vars *vars)
{
	raycast(vars);
	mini_map_draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->frame, 0, 0);
}

void	frame_pixel_draw(void *img, int x, int y, int color)
{
	char	*dst;
	int		bpp;
	int		size_line;
	int		endian;

	dst = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	dst += y * size_line + x * (bpp / 8);
	*(unsigned int*)dst = rgb_alpha(*(unsigned int*)dst, color);
}

