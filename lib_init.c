/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 20:48:08 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/06 23:57:25 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		glib_init(void *eng, t_glib *glib)
{
	int	wd;
	int ht;

	eng_get_window_size(eng, &wd, &ht);
	glib->mlx = mlx_init();
	if (glib->mlx == NULL)
		return (FAILURE);
	glib->win = mlx_new_window(glib->mlx, wd, ht, "cub3D");
	if (glib->win == NULL)
		return (FAILURE);
	glib->frame = mlx_new_image(glib->mlx, wd, ht);
	if (glib->frame == NULL)
		return (FAILURE);
	return (SUCCESS);
}
