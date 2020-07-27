/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_pixel_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 19:42:53 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/27 15:11:02 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

unsigned	*mlx_image_pixel_ptr(void *img, int x, int y)
{
	char	*dst;
	int		bpp;
	int		size_line;
	int		endian;

	dst = mlx_get_data_addr(img, &bpp, &size_line, &endian);
	dst += y * size_line + x * (bpp / 8);
	return ((unsigned *)dst);
}
