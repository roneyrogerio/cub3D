/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng_set_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 21:43:28 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/06 23:20:37 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_int.h"

void	eng_set_walk(t_eng *eng, int value)
{
	eng->player.walk = value;
}

void	eng_set_turn(t_eng *eng, int value)
{
	eng->player.turn = value;
}
