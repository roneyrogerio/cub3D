/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:04:24 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/07/28 14:42:46 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int		c3d_frame(t_c3d *c3d)
{
	int	wd;
	int ht;

	ngn_get_window_size(c3d->ngn, &wd, &ht);
	if (c3d->save && (c3d->frame = lbmp_new(wd, ht, 32)))
	{
		ngn_camera(c3d->ngn, &c3d_lbmp_draw);
		ngn_mini_map(c3d->ngn, &c3d_lbmp_draw);
		lbmp_save("cub3D.bmp", c3d->frame);
		return (EXIT_SUCCESS);
	}
	if ((c3d->frame = mlx_new_image(c3d->mlx, wd, ht)))
	{
		ngn_camera(c3d->ngn, &c3d_mlx_draw);
		ngn_mini_map(c3d->ngn, &c3d_mlx_draw);
		mlx_put_image_to_window(c3d->mlx, c3d->win, c3d->frame, 0, 0);
		mlx_destroy_image(c3d->mlx, c3d->frame);
		c3d->frame = NULL;
		ngn_movement_update(c3d->ngn);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
