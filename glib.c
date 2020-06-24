/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glib.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 20:48:08 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/14 04:54:39 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		glib_init(t_glib *glib)
{
	glib->mlx = mlx_init();
	if (glib->mlx == NULL)
		return (FAILURE);
	return (SUCCESS);
}

int		window_init(void *ngn, t_glib *glib)
{
	int	wd;
	int ht;

	ngn_get_window_size(ngn, &wd, &ht);
	glib->win = mlx_new_window(glib->mlx, wd, ht, "cub3D");
	if (glib->win == NULL)
		return (FAILURE);
	return (SUCCESS);
}

