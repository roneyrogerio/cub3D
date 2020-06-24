/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_alpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 23:25:16 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/24 07:11:01 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	rgb_alpha(int rgb1, int rgb2)
{
	static t_alpha	var;

	var.rgb1.r = (rgb1 >> 16) & 0xFF;
	var.rgb1.g = (rgb1 >> 8) & 0xFF;
	var.rgb1.b = (rgb1 >> 0) & 0xFF;
	var.rgb2.a = ((rgb2 >> 24) & 0xFF) / 255.0;
	var.rgb2.r = (rgb2 >> 16) & 0xFF;
	var.rgb2.g = (rgb2 >> 8) & 0xFF;
	var.rgb2.b = (rgb2 >> 0) & 0xFF;
	var.rgb1.r = var.rgb1.r * (1.0 - var.rgb2.a) + var.rgb2.r * var.rgb2.a;
	var.rgb1.g = var.rgb1.g * (1.0 - var.rgb2.a) + var.rgb2.g * var.rgb2.a;
	var.rgb1.b = var.rgb1.b * (1.0 - var.rgb2.a) + var.rgb2.b * var.rgb2.a;
	return (var.rgb1.r * 65536 + var.rgb1.g * 256 + var.rgb1.b);
}
