# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solopov <solopov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 11:44:13 by asolopov          #+#    #+#              #
#    Updated: 2019/11/18 21:46:19 by solopov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags 'n colors

CFLAGS		= -Wall -Werror -Wextra -O3
GREEN = \033[1;32m
RES = \033[0m
RED = \033[1;31m

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

EXECSRCS = $(addprefix $(SRCDIR), $(EXECSRC))

# Libft files

LIBNAME		= libft.a

LIBSRC		= ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_realloc.c \
			get_next_line.c \

LIBOBJ = $(LIBSRC:.c=.o)

LIBSRCS = $(addprefix $(LIBDIR), $(LIBSRC))
LIBOBJS = $(addprefix $(LIBDIR), $(LIBOBJ))
LIBFILE = $(addprefix $(LIBDIR), $(LIBNAME))

# Directories

LIBDIR = ./libft/
SRCDIR = ./srcs/
OBJDIR = ./obj/
INCDIR = ./includes/

# MLX link

MLX_LNK		= /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(LIBNAME)

$(EXECNAME):
	@echo "$(RED)Compiling $(EXECNAME)...$(RES)"
	gcc -o $(EXECNAME) $(CFLAGS) $(LIBFILE) $(EXECSRCS) -L $(MLX_LNK)
	@echo "$(EXECNAME) Compiled!"

$(LIBNAME): $(EXECNAME)
	@echo "$(RED)Creating library...$(RES)"
	@gcc -c $(CFLAGS) $(LIBSRCS)
	@ar rc $(LIBNAME) $(LIBOBJ)
	@ranlib $(LIBNAME)
	@echo "$(GREEN)Library Created.$(RES)"

clean:
	@echo "$(RED)Deleting Objects...$(RES)"
	@/bin/rm -f $(LIBOBJS)
	@echo "$(GREEN)Objects deleted.$(RES)"

fclean: clean
	@echo "$(RED)Deleting Executable...$(RES)"
	@/bin/rm -f $(EXECNAME)
	@echo "$(GREEN)Executable deleted.$(RES)"

re: fclean all