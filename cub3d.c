/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 18:00:06 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/14 04:53:06 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_vars *vars;

	if (argc == 1 && argv[0])
	{
		write(2, "\e[31mMissing configuration file in the argument\n", 48);
		exit(FAILURE);
	}
	vars = get_vars();
	if (!(vars->ngn = ngn_init()))
		quit(&vars->glib);
	if (glib_init(&vars->glib) == FAILURE)
		quit(&vars->glib);
	if (argc >= 3 && !ft_strncmp(argv[2], "--save", 6) && argv[2][6] == '\0')
		write(1, "teste", 5);
	if (window_init(vars->ngn, &vars->glib) == FAILURE)
		quit(&vars->glib);
	mlx_loop_hook(vars->glib.mlx, frame, vars);
	mlx_hook(vars->glib.win, 2, 1, key_press, vars);
	mlx_hook(vars->glib.win, 3, 2, key_release, vars);
	mlx_loop(vars->glib.mlx);
	return (SUCCESS);
}
