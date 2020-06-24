/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:04:24 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/14 04:53:56 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		frame(t_vars *vars)
{
	int	wd;
	int ht;

	ngn_movement_update(vars->ngn);
	ngn_get_window_size(vars->ngn, &wd, &ht);
	vars->glib.frame = mlx_new_image(vars->glib.mlx, wd, ht);
	if (vars->glib.frame == NULL)
		return (FAILURE);
	ngn_mini_map(vars->ngn, &frame_draw);
	mlx_put_image_to_window(
			vars->glib.mlx, vars->glib.win, vars->glib.frame, 0, 0);
	mlx_destroy_image(vars->glib.mlx, vars->glib.frame);
	vars->glib.frame = NULL;
	return (0);
}

void		frame_draw(int x, int y, int color)
{
	void		*img;
	unsigned	*pixel;

	img = (get_vars())->glib.frame;
	pixel = mlx_image_pixel_ptr(img, x, y);
	*pixel = rgb_alpha(*pixel, color);
}
