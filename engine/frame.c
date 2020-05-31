/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:04:24 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/31 01:15:15 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	frame(t_vars *vars)
{
	raycast(vars);
	mini_map_draw(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
