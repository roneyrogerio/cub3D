/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng_int_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 00:01:59 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/08 03:31:39 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_int.h"

void	eng_int_circle(t_circle *circle, void (*draw)(int, int, int))
{
	int	height;
	int	x;
	int y;

	x = -circle->radius;
	while (x < circle->radius)
	{
		height = (int)sqrt(circle->radius * circle->radius - x * x);
		y = -height;
		while (y < height)
		{
			draw(x + circle->x, y + circle->y, circle->color);
			y++;
		}
		x++;
	}
}
