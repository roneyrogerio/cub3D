# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 21:55:18 by rde-oliv          #+#    #+#              #
#    Updated: 2020/06/24 07:18:43 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = clang
SRC = c3d.c c3d_frame.c c3d_key_event.c c3d_window_init.c c3d_quit.c \
	  mlx_image_pixel_ptr.c c3d_draw.c rgb_alpha.c 
OBJS = $(SRC:.c=.o)
CFLAGS = -Werror -Wextra -Wall
LIBS = -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): libft/libft.a raycast-engine/_ngn.a libbmp24/lbmp.a $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a raycast-engine/_ngn.a \
	   	libbmp24/lbmp.a $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I libft -I raycast-engine -I libbmp24

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

libbmp24/Makefile:
	git submodule update --init libbmp24

libbmp24/lbmp.a: libbmp24/Makefile libbmp24
	make -C libbmp24
	touch libbmp24/lbmp.a

clean:
	make clean -C libft
	make clean -C raycast-engine
	make clean -C libbmp24
	rm -f $(OBJS)

fclean: clean
	make fclean -C libft
	make fclean -C raycast-engine
	make fclean -C libbmp24
	rm -f $(NAME)

re: fclean $(NAME)
