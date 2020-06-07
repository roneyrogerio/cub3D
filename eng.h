/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eng.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:30:50 by rde-oliv          #+#    #+#             */
/*   Updated: 2020/06/07 01:06:39 by rde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENG_H
# define ENG_H

void	eng_camera(void *core, void (*draw)(int, int, int));
void	eng_mini_map(void *eng, void (*draw)(int, int, int));
void	*eng_init(void);
void	eng_get_window_size(void *eng, int *wd, int *ht);
void	eng_set_walk(void *eng, int value);
void	eng_set_turn(void *eng, int value);

#endif
