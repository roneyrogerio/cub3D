# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 21:55:18 by rde-oliv          #+#    #+#              #
#    Updated: 2020/06/11 04:13:07 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = engine.a
CC = clang
SRC = eng_init.c eng_camera.c eng_mini_map.c eng_get_window_size.c \
	  eng_int_get_mini_map_pos.c eng_int_circle.c eng_set_movement.c \
	  eng_int_getline.c eng_config_file.c
OBJS = $(SRC:.c=.o)
CFLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
