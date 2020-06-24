# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 21:55:18 by rde-oliv          #+#    #+#              #
#    Updated: 2020/06/23 19:20:46 by rde-oliv         ###   ########.fr        #
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

$(NAME): libft/libft.a raycast-engine/eng.a $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)/$(LIBFT_A) \
		$(ENG)/$(ENG_A) $(LIBS) -I $(LIBFT) -I $(ENG)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft/Makefile:
	git submodule update --init $(LIBFT)

libft/libft.a: libft/Makefile libft
	make -C libft
	touch libft/libft.a

raycast-engine/Makefile:
	git submodule update --init raycast-engine

raycast-engine/_eng.a: raycast-engine/Makefile
	make _eng.a -C $(ENG)
	touch raycast-engine/_eng.a

clean:
	make clean -C $(LIBFT)
	make clean -C $(ENG)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(ENG)
	rm -f $(NAME)

re: fclean $(NAME)
