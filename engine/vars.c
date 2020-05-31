/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:22:14 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/30 23:44:31 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_vars	*my_vars(void)
{
	static t_vars	vars;

	return (&vars);
}

void	vars_setup(t_vars *vars)
{
	vars->ht = 593;
	vars->wd = 800;
	vars->mx_wd = 14;
	vars->mx_ht = 24;
	mini_map_setup();
}
