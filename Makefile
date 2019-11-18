# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asolopov <asolopov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 11:44:13 by asolopov          #+#    #+#              #
#    Updated: 2019/11/18 19:27:54 by asolopov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable files

EXECNAME	=	fdf

EXECSRC		= input_processor.c\
			line_algorithm.c\
			color_manager.c\
			perspectives.c\
			map_controls.c\
			init_reset.c\
			extra.c\
			main.c

EXECOBJ 	= $(addprefix $(OBJDIR), $(EXECSRC:.c=.o))

# Flags

CFLAGS		= -Wall -Werror -Wextra

# Libft Library

FT			= ./libft/

FT_LIB		= $(addprefix $(FT), libft.a)
FT_INC		= -I ./libft
FT_LNK		= -L ./libft -l ft

# MinilibX link

MLX_LNK		= /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit

# Directories

SRCDIR		= ./srcs/
INCDIR		= ./includes/
OBJDIR		= ./obj/

all: obj $(FT_LIB) $(EXECNAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	gcc $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(EXECNAME): $(EXECOBJ)
	gcc $(EXECOBJ) -L $(MLX_LNK) $(FT_LNK) -lm -o $(EXECNAME)

clean:
	/bin/rm -f $(EXECOBJ)
	
fclean: clean
	/bin/rm -f $(EXECNAME)

re: fclean all
