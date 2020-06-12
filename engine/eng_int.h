/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng_int.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:30:50 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/11 04:31:23 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENG_INT_H
# define ENG_INT_H
# include <unistd.h>
# include <math.h>
# include <stdlib.h>

typedef struct	s_map
{
	int	sz;
	int	mgn_x;
	int	mgn_y;
}				t_map;

typedef struct	s_player
{
	double	x;
	double	y;
	double	radius;
	int		turn;
	int		walk;
	int		side;
	double	angle;
	double	move_speed;
	double	turn_speed;
}				t_player;

typedef struct	s_eng
{
	int			wd;
	int			ht;
	int			**mx;
	int			mx_wd;
	int			mx_ht;
	t_map		map;
	t_player	player;
}				t_eng;

typedef struct	s_circle
{
	int	x;
	int	y;
	int	radius;
	int	color;
}				t_circle;

typedef struct	s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

typedef	struct	s_pseudo_fd
{
	char	buf[100];
	int		size;
	int		offset;
	t_list	*line_liststart;
	t_list	*line_listlast;
	int		list_hasline;
	int		list_linelen;
	int		i;
}				t_pseudo_fd;

int				rgb_map(int p);
void			eng_int_get_mini_map_pos(t_eng *eng, int *x, int *y);
void			eng_int_circle(t_circle *circle, void (*draw)(int, int, int));
int				list2line(t_pseudo_fd *pfd, char **line);
int				markup(t_pseudo_fd *pfd);
t_list			*lst_new(t_pseudo_fd *pfd);
int				eng_int_getline(int fd, char **line);
#endif
