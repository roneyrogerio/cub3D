/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:04:24 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/24 08:41:22 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int		c3d_frame(t_c3d *c3d)
{
	int	wd;
	int ht;

	ngn_get_window_size(c3d->ngn, &wd, &ht);
	if (c3d->save && lbmp_new(wd, ht))
	{
		ngn_mini_map(c3d->ngn, &c3d_lbmp_draw);
		lbmp_save("test.bmp", c3d->frame);
		return (EXIT_SUCCESS);
	}
	if((c3d->frame = mlx_new_image(c3d->mlx, wd, ht)))
	{
		ngn_mini_map(c3d->ngn, &c3d_mlx_draw);
		mlx_put_image_to_window(c3d->mlx, c3d->win, c3d->frame, 0, 0);
		mlx_destroy_image(c3d->mlx, c3d->frame);
		ngn_movement_update(c3d->ngn);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
