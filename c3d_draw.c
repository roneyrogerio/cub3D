/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 06:25:42 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/24 07:10:42 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	c3d_mlx_draw(int x, int y, int color)
{
	unsigned	*pixel;

	pixel = mlx_image_pixel_ptr(g_c3d.frame, x, y);
	*pixel = rgb_alpha(*pixel, color);
}

void	c3d_lbmp_draw(int x, int y, int color)
{
	lbmp_set_pixel_color(g_c3d.frame, x, y, color);
}
