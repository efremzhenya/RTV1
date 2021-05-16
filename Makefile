# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mellie <mellie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 13:17:58 by lseema            #+#    #+#              #
#    Updated: 2021/05/16 18:35:38 by mellie           ###   ########.fr        #
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
HEADERS		:= rtv1.h scene.h geometry.h token_actions.h jsmn.h

SRCS		:=	rtv1.c\
				json_parser.c\
				json_parser2.c\
				scene_manage.c\
				object_manage.c\
				token_manage.c\
				vector.c\
				vector2.c\
				matrix.c\
				cone.c\
				cylinder.c\
				plane.c\
				sphere.c\
				omnilight.c\
				camera.c\
				init_sdl.c\
				ray_trace.c\
				light.c\
				color.c
OBJS		:= $(SRCS:.c=.o)

DIR_SDL		:= external_libs/SDL/
MAKE_SDL	:= make -C $(DIR_SDL)

PATH_LIBFT	:= $(addprefix $(DIR_LIBFT), $(LIBFT))
PATH_JSMN	:= external_libs/jsmn/jsmn.a
MAKE_LIBFT := make -C $(DIR_LIBFT)

#rebuild dependencies
vpath %.c $(DIR_SRC)
vpath %.h $(DIR_INC)
vpath %.o $(DIR_OBJ)

#all: libft_target sdl_target $(MAIN)
all: libft_target $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(FLAGS) -lm `external_libs/SDL/bin/sdl2-config --cflags` $(addprefix $(DIR_OBJ), $(OBJS)) $(PATH_LIBFT) $(PATH_JSMN) -o $@ `external_libs/SDL/bin/sdl2-config --libs`
	@echo "rtv1 builded"

$(OBJS): %.o:%.c $(HEADERS) | $(DIR_OBJ)
	$(CC) -c $(FLAGS) $< -o $(DIR_OBJ)$@ -I $(DIR_INC) -I external_libs/SDL/SDL2-2.0.14/include

$(DIR_OBJ):
	mkdir -p $@

libft_target:
	$(MAKE_LIBFT)
	@echo "libft builded"

sdl_target:
	$(MAKE_SDL)
	@echo "sdl builded"

clean:
	/bin/rm -rf $(addprefix $(DIR_OBJ), $(OBJS))
	/bin/rm -rf $(DIR_OBJ)
	$(MAKE_LIBFT) clean
	$(MAKE_SDL) clean

fclean: clean
	/bin/rm -rf $(RTV1)
	$(MAKE_LIBFT) fclean
	$(MAKE_SDL) fclean

re: fclean all
