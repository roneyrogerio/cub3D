/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 22:15:14 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/28 06:55:54 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	c3d_quit(int ret_code)
{
	if (g_c3d.save && g_c3d.frame)
		lbmp_destroy(g_c3d.frame);
	else if (g_c3d.frame)
		mlx_destroy_image(g_c3d.mlx, g_c3d.frame);
	if (g_c3d.win)
		mlx_destroy_window(g_c3d.mlx, g_c3d.win);
	ngn_destroy(g_c3d.ngn);
	free(g_c3d.mlx);
	exit(ret_code);
}
