/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 18:00:06 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/09 23:03:10 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_vars *vars;

	vars = get_vars();
	if (!(vars->eng = eng_init()))
		quit(&vars->glib);
	if (glib_init(vars->eng, &vars->glib) == FAILURE)
		quit(&vars->glib);
	mlx_loop_hook(vars->glib.mlx, frame, vars);
	mlx_hook(vars->glib.win, 2, 1, key_press, vars);
	mlx_hook(vars->glib.win, 3, 2, key_release, vars);
	mlx_loop(vars->glib.mlx);
	return (SUCCESS);
}
