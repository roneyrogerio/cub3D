# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 21:55:18 by rde-oliv          #+#    #+#              #
#    Updated: 2020/06/29 05:11:00 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC   = clang
SRC  = c3d.c c3d_frame.c c3d_key_event.c c3d_window_init.c c3d_quit.c \
	  mlx_image_pixel_ptr.c c3d_draw.c rgb_alpha.c 
OBJS     := $(SRC:.c=.o)
CFLAGS    = -Werror -Wextra -Wall -g
LIBS      = -lmlx -lXext -lX11 -lm
SUBMOD    = ngn lbmp libft
SUBMK    := $(addsuffix /Makefile,$(SUBMOD))
SUBLIB   := $(foreach D,$(SUBMOD),$D/$D.a)
CMOD     := $(patsubst %,-I %,$(SUBMOD))

all: $(NAME)

$(NAME): $(SUBLIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(SUBLIB) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(CMOD)

.FORCE:
$(SUBLIB): .FORCE $(SUBMK)
	make -C $(@D)

$(SUBMK):
	git submodule update --init

clean:
	rm -f $(OBJS)
	@for module in $(SUBMOD); do \
		if [ -f $$module/Makefile ]; then make clean -C $$module; fi; \
	done

fclean: clean
	rm -f $(NAME)
	@for module in $(SUBMOD); do \
		if [ -f $$module/Makefile ]; then make fclean -C $$module; fi; \
	done

re: fclean $(NAME)
