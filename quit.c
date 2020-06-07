/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 22:15:14 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/06 23:58:50 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	quit(t_glib *glib)
{
	mlx_destroy_image(glib->mlx, glib->frame);
	mlx_destroy_window(glib->mlx, glib->win);
	exit(0);
}
