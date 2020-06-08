# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 21:55:18 by rde-oliv          #+#    #+#              #
#    Updated: 2020/06/08 01:18:21 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = clang
SRC = cub3d.c frame.c key_event.c lib_init.c get_vars.c quit.c \
	  mlx_image_pixel_ptr.c rgb_alpha.c
OBJS = $(SRC:.c=.o)
CFLAGS = -Werror -Wextra -Wall
LIBS = -lmlx -lXext -lX11 -lm
ENG = engine
ENG_LIB = engine.a

all: $(NAME)

eng:
	make -C $(ENG)
	cp $(ENG)/$(ENG_LIB) $(ENG_LIB)

$(NAME): eng $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(ENG_LIB) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(ENG)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(ENG)
	rm -f $(ENG_LIB)
	rm -f $(NAME)

re: fclean $(NAME)
