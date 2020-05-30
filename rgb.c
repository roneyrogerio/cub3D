/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:18:04 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/29 22:30:21 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	mapc(int p)
{
	if (p > 0)
		return (0xFF8900);
	if (p == 0)
		return (0xFFFFFF);
}

int	rgb_sum(int rgb, int rgb2, double alpha)
{
	int red;
	int green;
	int blue;
	int red2;
	int green2;
	int blue2;

	red = ((rgb >> 16) & 0xFF) * (1.0 - alpha);
	green = ((rgb >> 8) & 0xFF) * (1.0 - alpha);
	blue = ((rgb >> 0) & 0xFF) * (1.0 - alpha);
	red2 = ((rgb2 >> 16) & 0xFF) * alpha;
	green2 = ((rgb2 >> 8) & 0xFF) * alpha;
	blue2 = ((rgb2 >> 0) & 0xFF) * alpha;
	red += red2;
	green += green2;
	blue += blue2;
	return (red * 65536 + green * 256 + blue);
}
