/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng_mini_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 00:25:00 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/08 03:14:19 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eng_int.h"

static void	eng_player_draw(t_eng *eng, void (*frame_draw)(int, int, int));
static void	eng_map_draw(t_eng *eng, void (*frame_draw)(int, int, int));

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
  {1,0,0,0,0,0,0,1,0,0,0,0,0,1},
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

int	rgb_map(int p)
{
	if (p > 0)
		return (0xffFF8900);
	else if (p == 0)
		return (0xffFFFFFF);
	else if (p < 0)
		return (0x00000000);
	return (0);
}

void	eng_mini_map(t_eng *eng, void (*frame_draw)(int, int, int))
{
	eng_map_draw(eng, frame_draw);
	eng_player_draw(eng, frame_draw);
}

static void	eng_map_draw(t_eng *eng, void (*frame_draw)(int, int, int))
{
	int x;
	int y;
	int mx_x;
	int mx_y;

	eng_int_get_mini_map_pos(eng, &x, &y);
	while (x < eng->wd - eng->map.mgn_x)
	{
		while (y < eng->ht - eng->map.mgn_y)
		{
			mx_x = eng->mx_wd * eng->map.sz;
			mx_x = mx_x - (eng->wd - x - eng->map.mgn_x);
			mx_x /= eng->map.sz;
			mx_y = eng->mx_ht * eng->map.sz;
			mx_y = mx_y - (eng->ht - y - eng->map.mgn_y);
			mx_y /= eng->map.sz;
			frame_draw(x, y, rgb_map(mx[mx_y][mx_x]));
			y++;
		}
		y -= eng->mx_ht * eng->map.sz;
		x++;
	}
}

static void	eng_player_draw(t_eng *eng, void (*frame_draw)(int, int, int))
{
	t_circle	circle;
	int			map_x;
	int 		map_y;

	eng_int_get_mini_map_pos(eng, &map_x, &map_y);
	circle.x = map_x + round((eng->map.sz * eng->mx_wd) * eng->player.x);
	circle.y = map_y + round((eng->map.sz * eng->mx_ht) * eng->player.y);
	circle.radius = ceil(eng->map.sz * eng->player.radius);
	circle.color = 0xffff0000;
	eng_int_circle(&circle, frame_draw);
}
