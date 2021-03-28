# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 13:17:58 by lseema            #+#    #+#              #
#    Updated: 2021/03/27 20:43:57 by lseema           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror -g
MAIN		:= rtv1

DIR_SRC		:= src/
DIR_INC		:= include/
DIR_OBJ		:= obj/
DIR_LIBFT	:= libft/

LIBFT		:= libft.a
HEADERS		:= rtv1.h

SRCS		:= parser.c
OBJS		:= $(SRCS:.c=.o)

PATH_LIBFT	:= $(addprefix $(DIR_LIBFT), $(LIBFT))
MAKE_LIBFT := make -C $(DIR_LIBFT)

#rebuild dependencies
vpath %.c $(DIR_SRC)
vpath %.h $(DIR_INC)
vpath %.o $(DIR_OBJ)

all: libft_target $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(FLAGS) $(addprefix $(DIR_OBJ), $(OBJS)) $(PATH_LIBFT) -o $@
	@echo "rtv1 compiled"

$(OBJS): %.o:%.c $(HEADERS) | $(DIR_OBJ)
	$(CC) -c $(FLAGS) $< -o $(DIR_OBJ)$@ -I $(DIR_INC)

$(DIR_OBJ):
	mkdir -p $@

libft_target:
	$(MAKE_LIBFT)
	@echo "libft compiled"

clean:
	/bin/rm -rf $(addprefix $(DIR_OBJ), $(OBJS))
	/bin/rm -rf $(DIR_OBJ)
	$(MAKE_LIBFT) clean

fclean:
	clean
	/bin/rm -rf $(RTV1)
	$(MAKE_LIBFT) fclean

re: fclean all
