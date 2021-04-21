# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 18:35:01 by lseema            #+#    #+#              #
#    Updated: 2021/04/05 20:23:57 by lseema           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = SDL

SDL_DIR=SDL2-2.0.14
SDL_ARCHIVE=$(SDL_DIR).tar.gz
BUILD_DIR = sdl_lib/

CLEAN_DIRS=$(BUILD_DIR) bin share
FCLEAN_DIRS=lib include $(SDL_DIR)

INSTALL_PATH=$(CURDIR)/

.PHONY: clean fclean all

all: $(NAME)

$(NAME):
	@tar -xvf $(SDL_ARCHIVE)
	@mkdir -vp $(BUILD_DIR) && cd $(BUILD_DIR) && ../$(SDL_DIR)/configure --prefix=$(INSTALL_PATH)
	@make -C $(BUILD_DIR)
	@make -C $(BUILD_DIR) install

clean:
	@rm -rf $(CLEAN_DIRS)

fclean: clean
	@rm -rf $(FCLEAN_DIRS)

re: fclean all
