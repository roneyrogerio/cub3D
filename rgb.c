/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:18:04 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/30 02:22:15 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rgb_map(int p)
{
	if (p > 0)
		return (0x80FF8900);
	if (p == 0)
		return (0x80FFFFFF);
}

int	rgb_alpha(int rgb1, int rgb2)
{
	t_alpha	v;

	v.rgb1.r = (rgb1 >> 16) & 0xFF;
	v.rgb1.g = (rgb1 >> 8) & 0xFF;
	v.rgb1.b = (rgb1 >> 0) & 0xFF;
	v.rgb2.a = ((rgb2 >> 24) & 0xFF);
	v.rgb2.a = v.rgb2.a != 0 ? v.rgb2.a / 255.0 : 1;
	v.rgb2.r = (rgb2 >> 16) & 0xFF;
	v.rgb2.g = (rgb2 >> 8) & 0xFF;
	v.rgb2.b = (rgb2 >> 0) & 0xFF;
	v.rgb1.r = v.rgb1.r * (1.0 - v.rgb2.a) + v.rgb2.r * v.rgb2.a;
	v.rgb1.g = v.rgb1.g * (1.0 - v.rgb2.a) + v.rgb2.g * v.rgb2.a;
	v.rgb1.b = v.rgb1.b * (1.0 - v.rgb2.a) + v.rgb2.b * v.rgb2.a;
	return (v.rgb1.r * 65536 + v.rgb1.g * 256 + v.rgb1.b);
}
