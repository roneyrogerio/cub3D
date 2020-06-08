/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng_int_get_mini_map_pos.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 22:58:24 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/08 01:36:27 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_int.h"

void	eng_int_get_mini_map_pos(t_eng *eng, int *x, int *y)
{
	*x = eng->wd - eng->mx_wd * eng->map.sz - eng->map.mgn_x;
	*y = eng->ht - eng->mx_ht * eng->map.sz - eng->map.mgn_y;
}
