# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 11:44:13 by asolopov          #+#    #+#              #
#    Updated: 2019/11/18 17:38:11 by asolopov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  fdf

CFLAGS = -Wall -Werror -Wextra

FTS =	input_processor.c\
		line_algorithm.c\
		color_manager.c\
		perspectives.c\
		map_controls.c\
		init_reset.c\
		extra.c\
		main.c\


LMXLIB = /usr/local/lib/ -lmlx

LIBFT = ./libft/libft.a

FTO = $(FTS:.c=.o)

.PHONY: all clean fclean re 

all: $(NAME)

$(NAME):
		gcc -o $(NAME) $(FLAGS) $(FTS) -L $(LMXLIB) $(LIBFT) -framework OpenGL -framework AppKit

clean:
	/bin/rm -f $(FTO)
	
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
