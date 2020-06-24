# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 21:55:18 by rde-oliv          #+#    #+#              #
#    Updated: 2020/06/24 00:27:39 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = clang
SRC = cub3d.c frame.c key_event.c glib.c get_vars.c quit.c \
	  mlx_image_pixel_ptr.c rgb_alpha.c
OBJS = $(SRC:.c=.o)
CFLAGS = -Werror -Wextra -Wall
LIBS = -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): libft/libft.a raycast-engine/_ngn.a $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a \
		raycast-engine/_ngn.a $(LIBS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I libft -I raycast-engine

libft/Makefile:
	git submodule update --init libft

libft/libft.a: libft/Makefile libft
	make -C libft
	touch libft/libft.a

raycast-engine/Makefile:
	git submodule update --init raycast-engine

raycast-engine/_ngn.a: raycast-engine/Makefile raycast-engine
	make _ngn.a -C raycast-engine
	touch raycast-engine/_ngn.a

clean:
	make clean -C libft
	make clean -C raycast-engine
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	make fclean -C raycast-engine
	rm -f $(NAME)

re: fclean $(NAME)
