/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 00:25:00 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/05/31 23:27:09 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int mx[24][24]=
{
  {-1,-1,-1,1,1,1,1,1,1,1,1,1,1,1},
  {-1,-1,-1,1,0,0,0,0,0,0,0,0,0,1},
  {-1,-1,-1,1,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	mini_map_setup(t_vars *vars)
{
	vars->map.size = (vars->ht < vars->wd ? vars->ht : vars->wd) / 5;
	vars->map.slice = vars->map.size;
	vars->map.slice /= vars->mx_ht > vars->mx_wd ? vars->mx_ht : vars->mx_wd;
	vars->map.mgn_x = vars->wd / 20;
	vars->map.mgn_y = vars->ht / 16;
}

void	mini_map_draw(t_vars *vars)
{
	int x;
	int y;
	int mx_x;
	int mx_y;

	x = vars->wd - (vars->mx_wd * vars->map.slice) - vars->map.mgn_x;
	while (x < vars->wd - vars->map.mgn_x)
	{
		y = vars->ht - vars->mx_ht * vars->map.slice - vars->map.mgn_y;
		while (y < vars->ht - vars->map.mgn_y)
		{
			mx_x = vars->mx_wd * vars->map.slice;
			mx_x = mx_x - (vars->wd - x - vars->map.mgn_x);
			mx_x = (mx_x - mx_x % vars->map.slice) / vars->map.slice;
			mx_y = vars->mx_ht * vars->map.slice;
			mx_y = mx_y - (vars->ht - y - vars->map.mgn_y);
			mx_y = (mx_y - mx_y % vars->map.slice) / vars->map.slice;
			frame_pixel_draw(vars->frame, x, y, rgb_map(mx[mx_y][mx_x]));
			y++;
		}
		x++;
	}
}
