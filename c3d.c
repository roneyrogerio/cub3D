/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 18:00:06 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/26 20:45:29 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

int	main(int argc, char **argv)
{
	if (argc == 1 && argv[0])
	{
		ft_putstr_fd("Missing configuration file in the argument\n", 2);
		c3d_quit(EXIT_FAILURE);
	}
	if ((g_c3d.ngn = ngn_init(argv[1])) == NULL)
	{
		ft_putstr_fd((char *)ngn_strerror(g_ngnerr), 2);
		c3d_quit(EXIT_FAILURE);
	}
	if (argc >= 3 && !ft_strncmp(argv[2], "--save", 6) && argv[2][6] == '\0')
	{
		g_c3d.save = 1;
		c3d_frame(&g_c3d);
		c3d_quit(EXIT_SUCCESS);
	}
	if (c3d_window_init() == EXIT_FAILURE)
		c3d_quit(EXIT_FAILURE);
	mlx_loop_hook(g_c3d.mlx, &c3d_frame, &g_c3d);
	mlx_hook(g_c3d.win, 2, 1, &c3d_key_press, &g_c3d);
	mlx_hook(g_c3d.win, 3, 2, &c3d_key_release, &g_c3d);
	mlx_loop(g_c3d.mlx);
	return (EXIT_SUCCESS);
}
