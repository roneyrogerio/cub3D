# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 21:55:18 by rde-oliv          #+#    #+#              #
#    Updated: 2020/06/14 05:16:14 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = clang
SRC = cub3d.c frame.c key_event.c glib.c get_vars.c quit.c \
	  mlx_image_pixel_ptr.c rgb_alpha.c
OBJS = $(SRC:.c=.o)
CFLAGS = -Werror -Wextra -Wall
LIBS = -lmlx -lXext -lX11 -lm
ENG = 3d_engine
ENG_A = eng.a
ENG_H = eng.h
LIBFT = libft
LIBFT_A = libft.a
LIBFT_H = libft.h

all: $(NAME)

$(NAME): $(LIBFT_A) $(ENG_A) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A) $(ENG_A) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_A):
	make -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_A) .
	cp $(LIBFT)/$(LIBFT_H) .
	cp $(LIBFT)/$(LIBFT_H) $(ENG)

$(ENG_A):
	make nolibft -C $(ENG)
	cp $(ENG)/$(ENG_A) .
	cp $(ENG)/$(ENG_H) .

clean:
	make clean -C $(LIBFT)
	make clean -C $(ENG)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT)
	make fclean -C $(ENG)
	rm -f $(NAME)
	rm -f $(LIBFT_A)
	rm -f $(LIBFT_H)
	rm -f $(ENG_A)
	rm -f $(ENG_H)

re: fclean $(NAME)
