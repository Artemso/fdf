# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 11:44:13 by asolopov          #+#    #+#              #
#    Updated: 2019/11/13 11:59:38 by asolopov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  fdf

CFLAGS = -Wall -Werror -Wextra

FTS =	main.c\
		get_input.c\
		line_algo.c\
		map_controls.c

LMXLIB = /usr/local/lib/ -lmlx

LIBFT = ./libft/libft.a

FTO = $(FTS:.c=.o)

.PHONY: all clean fclean re 

all: $(NAME)

$(NAME):
		gcc -o $(NAME) $(CFLAGS) $(FTS) -L $(LMXLIB) $(LIBFT) -framework OpenGL -framework AppKit

clean:
	/bin/rm -f $(FTO)
	
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
