/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 22:15:14 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/14 04:55:26 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit(t_glib *glib)
{
	if (!glib)
		return (0);
	if (glib->frame)
		mlx_destroy_image(glib->mlx, glib->frame);
	if (glib->win)
		mlx_destroy_window(glib->mlx, glib->win);
	free(glib->mlx);
	exit(0);
}
