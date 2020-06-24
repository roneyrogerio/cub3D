/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_window_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 20:48:08 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/24 07:07:08 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int		c3d_window_init(void)
{
	int	wd;
	int ht;

	if ((g_c3d.mlx = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	ngn_get_window_size(g_c3d.ngn, &wd, &ht);
	if ((g_c3d.win = mlx_new_window(g_c3d.mlx, wd, ht, "cub3D")) == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
