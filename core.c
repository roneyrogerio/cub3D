/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:22:14 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/29 22:29:46 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_core	*mcore(void)
{
	static t_core	core;

	return (&core);
}

void	core_init(t_core *core)
{
	core->ht = 593;
	core->wd = 800;
	core->mxwd = 14;
	core->mxht = 24;
	map_setup(core);
}
