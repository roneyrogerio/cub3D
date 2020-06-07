/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 19:56:58 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/06 20:06:03 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_int.h"

static double	rand_double(void)
{
	return (rand() / (double)RAND_MAX);
}

static int		rand_int(int a, int b)
{
	return ((int)((b - a + 1) * rand_double()) + a);
}

void			camera(t_eng *eng, void (*draw)(int, int, int))
{
	int i;
	int j;

	i = 0;
	while (i < eng->ht)
	{
		j = 0;
		while (j < eng->wd)
		{
			if (rand_int(0, 1))
				draw(j, i, 0xFFffffff);
			else
				draw(j, i, 0x80181a18);
			j++;
		}
		i++;
	}
}
