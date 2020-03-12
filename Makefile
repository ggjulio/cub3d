# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m

# Colors
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_ICYAN=$'\x1b[46m
_IWHITE=$'\x1b[47m

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 18:50:56 by juligonz          #+#    #+#              #
#    Updated: 2020/03/12 10:44:21 by juligonz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Cub3D

LIB = ft mlx z
FRAMEWORKS = OpenGL AppKit

SRC_DIR = $(shell find ./srcs -type d)
INC_DIR = includes
OBJ_DIR = obj
LIB_DIR = $(shell find ./lib -type d -maxdepth 1)

SRC = main.c
SRC+= timing.c
SRC+= application.c application_util.c application_window.c
SRC+= game.c game_util.c game_draw_map.c game_hud.c
SRC+= sprite.c sprite_util.c
SRC+= bmp.c
SRC+= image.c image_load.c image_manipulation.c image_util.c image_util2.c 
SRC+= move.c move_mouse.c move_movement.c move_movement_camera.c
SRC+= events.c events_key.c events_effects.c
SRC+= raycast.c raycast_util.c raycast_effects.c raycast_util_calc.c
SRC+= vector.c vector_util.c
SRC+= fvector.c fvector_basic_operation.c fvector_cast.c fvector_rotation.c
SRC+= color.c color_utility.c color_str.c
SRC+= parser.c parser2.c parse_map.c parse_map2.c
SRC+= draw.c move.c camera.c
SRC+= texture.c utility.c

OBJ = $(addprefix  $(OBJ_DIR)/,$(SRC:%.c=%.o))
vpath %.c $(SRC_DIR)

LFLAGS = $(foreach lib, $(LIB_DIR),-L$(lib))  $(foreach lib, $(LIB),-l$(lib))
LFLAGS+= $(foreach framework, $(FRAMEWORKS),-framework $(framework))

CC = gcc
CFLAGS  = -Wall -Wextra -Werror -g # -fsanitize=address  -fsanitize=undefined -fstack-protector  
IFLAGS  = -I./lib/libmlx -I./lib/libft -I./includes

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "$(_GREEN)Compiling ...$(_END)"
	@$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o $@ $^
	@echo "$(_GREEN)Compiled !$(_END)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(_GREEN).o removed !$(_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_GREEN)$(NAME) program removed !$(_END)"

bonus: $(NAME)

show:
	@echo "$(_CYAN)SRC_DIR    :$(_RED)  $(SRC_DIR)$(_END)"
	@echo "$(_CYAN)SRC    :$(_RED)  $(SRC)$(_END)"
	@echo "$(_CYAN)OBJ    :$(_RED)  $(OBJ)$(_END)"
	@echo "$(_CYAN)IFLAGS :$(_RED)  $(IFLAGS)$(_END)"
	@echo "$(_CYAN)LFLAGS :$(_RED)  $(LFLAGS)$(_END)"
	@echo "$(_CYAN)CFLAGS :$(_RED)  $(CFLAGS)$(_END)"

re: fclean all


install: 
	@echo "$(_GREEN)Install libft.a ...$(_END)"
	@make -s -C lib/libft/
	@echo "$(_RED)done ...$(_END)"
	@echo "$(_GREEN)Install libmlx.a ...$(_END)"
	@make -s -i CFLAGS+=-w -C lib/libmlx/
	@echo "$(_RED)done ...$(_END)"

fclean-install:
	@echo "$(_GREEN)fclean-install libft.a ...$(_END)"
	@make fclean -s -C lib/libft/
	@echo "$(_GREEN)fclean-install libmlx.a ...$(_END)"
	@make clean -s -i CFLAGS+=-w -C lib/libmlx/

re-install: fclean-install install



.PHONY: clean fclean re all bonus install re-install fclean-install


#******************************************************************************#
#                                  REMINDER                                    #  
#******************************************************************************# \
                                                                                 \
                                                                                 \
Automatic variables :                                                            \
                                                                                 \
$@ : rule name  target.         			                                     \
                                                                                 \
$^ : The names of all the prerequisites, with spaces between them. For           \
prerequisites which are archive members, only the named member is used.          \
                                                                                 \
$< : The name of the first prerequisite. If the target got its recipe from an    \
implicit rule, this will be the first prerequisite added by the implicit rule.   \
                                                                                 \
$? : The names of all the prerequisites that are newer than the target, with     \
spaces between them. For prerequisites which are archive members, only the       \
named member is used.                                                            \
                                                                                 \
                                                                                 \
source :                                                                         \
https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html      \

#******************************************************************************#
#                                  RESSOURCES                                  #  
#******************************************************************************# \
resources :                                                                      \
https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents       \
http://web.mit.edu/gnu/doc/html/make_toc.html#SEC88                              \
https://www3.nd.edu/~zxu2/acms60212-40212/Makefile.pdf                           \