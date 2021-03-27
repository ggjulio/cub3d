# https://misc.flogisoft.com/bash/tip_colors_and_formatting
_BOLD      =\e[1m
_DIM       =\e[2m
_UNDERLINE =\e[4m
_BLINK     =\e[5m
_REVERSE   =\e[7m
_HIDDEN    =\e[8m

# RESET list
_R          =\e[0m
_RBOLD      =\e[21m
_RDIM       =\e[22m
_RUNDERLINE =\e[24m
_RBLINK     =\e[25m
_RREVERSE   =\e[27m
_RHIDDEN    =\e[28m

# Colors
_RED      =\e[91m
_GREEN    =\e[92m
_YELLOW   =\e[93m
_BLUE     =\e[94m
_MAGENTA  =\e[35m
_CYAN     =\e[96m
_WHITE    =\e[97m

# Inverted, i.e. colored backgrounds
_IRED     =\e[101m
_IGREEN   =\e[102m
_IYELLOW  =\e[103m
_IBLUE    =\e[104m
_IMAGENTA =\e[45m
_ICYAN    =\e[106m
_IWHITE   =\e[107m

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 18:50:56 by juligonz          #+#    #+#              #
#    Updated: 2020/03/13 00:20:54 by juligonz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Cub3D
UNAME := $(shell uname)

LIB = ft mlx fmod
ifeq ($(UNAME), Darwin)
	# macos
else
	#Linux and others...
	LIB+= pthread Xext X11 m
endif

SRC_DIR = $(shell find ./srcs -type d)
INC_DIR = includes
OBJ_DIR = obj
LIB_DIR = $(shell find ./lib -maxdepth 1 -type d )

SRC = main.c
SRC+= timing.c sound_management.c
SRC+= application.c application_util.c application_window.c
SRC+= game.c game_util.c game_map.c game_hud.c game_life.c
SRC+= sprite.c sprite_util.c
SRC+= bmp.c
SRC+= image.c image_load.c image_manipulation.c image_util.c image_util2.c 
SRC+= move.c move_mouse.c move_movement.c move_movement_camera.c
SRC+= events.c events_key.c events_effects.c
SRC+= raycast.c raycast_dda.c raycast_util.c raycast_effects.c raycast_util_calc.c
SRC+= vector.c vector_util.c
SRC+= fvector.c fvector_basic_operation.c fvector_cast.c fvector_rotation.c
SRC+= color.c color_utility.c color_str.c
SRC+= parser.c parser2.c parse_map.c parse_map2.c
SRC+= draw.c camera.c
SRC+= texture.c utility.c

OBJ = $(addprefix  $(OBJ_DIR)/,$(SRC:%.c=%.o))
vpath %.c $(SRC_DIR)


CC = clang
CFLAGS  = -Wall -Wextra -Werror -g # -fsanitize=address  -fsanitize=undefined -fstack-protector  
IFLAGS  = -I./lib/libft -I./lib/libmlx -I./lib/libfmod_$(UNAME) -I./includes 
LFLAGS 	= -L./lib/libft -L./lib/libmlx -L./lib/libfmod_$(UNAME)
LFLAGS += $(foreach lib, $(LIB),-l$(lib))

ifeq ($(UNAME), Darwin)
	# DYLD_LIBRARY_PATH=lib/libfmod
	# FRAMEWORKS = OpenGL AppKit
	# LFLAGS+= $(foreach framework, $(FRAMEWORKS),-framework $(framework))
endif

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

ifeq ($(UNAME), Darwin)
$(NAME): $(OBJ)
	@printf "$(_GREEN)Compiling for Darwin...$(_R)\n"
	@$(CC) $(CFLAGS) $(IFLAGS)  -o $@ $(OBJ) $(LFLAGS)
	@install_name_tool -change "@rpath/libfmod.dylib" "lib/libfmod/libfmod_Darwin.dylib" $(NAME)
	@printf "$(_GREEN)Compiled !$(_R)\n"
else
# Linux
$(NAME): $(OBJ)
	@printf "$(_GREEN)Compiling for Linux...$(_R)\n"
	@$(CC) $(CFLAGS) $(IFLAGS)  -o $@ $(OBJ) $(LFLAGS)
	@printf "$(_GREEN)Compiled !$(_R)\n"
	@printf "$(_YELLOW)Run $(_RED) eval \$$(make env)$(_YELLOW)  to set LD_LIBRARY_PATH$(_R)\n"
env:
	export LD_LIBRARY_PATH="$(shell pwd)/lib/libfmod_Linux:$(LD_LIBRARY_PATH)"
endif

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(_GREEN).o removed !$(_R)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(_GREEN)$(NAME) program removed !$(_R)\n"

bonus: $(NAME)

show:
	@printf "$(_CYAN)CC     :$(_RED)  $(CC)$(_R)\n"
	@printf "$(_CYAN)CFLAGS :$(_RED)  $(CFLAGS)$(_R)\n"
	@printf "$(_CYAN)IFLAGS :$(_RED)  $(IFLAGS)$(_R)\n\n"
	@printf "$(_CYAN)LIB    :$(_RED)  $(LIB)$(_R)\n"
	@printf "$(_CYAN)LIB_DIR:$(_RED)  $(LIB_DIR)$(_R)\n"
	@printf "$(_CYAN)LFLAGS :$(_RED)  $(LFLAGS)$(_R)\n\n"
	@printf "$(_CYAN)SRC_DIR:$(_RED)  $(SRC_DIR)$(_R)\n\n"
	@printf "$(_CYAN)SRC    :$(_RED)  $(SRC)$(_R)\n"
	@printf "$(_CYAN)OBJ    :$(_RED)  $(OBJ)$(_R)\n"

re: fclean all


install: 
	@printf "$(_GREEN)Install libft.a ...$(_R)\n"
	@make  -C lib/libft/
	@printf "$(_RED)done ...$(_R)\n"
	@printf "$(_GREEN)Install libmlx.a ...$(_R)\n"
	@make  -i -C lib/libmlx/
	@printf "$(_RED)done ...$(_R)\n"

fclean-install:
	@printf "$(_GREEN)fclean-install libft.a ...$(_R)\n"
	@make fclean -s -C lib/libft/
	@printf "$(_GREEN)fclean-install libmlx.a ...$(_R)\n"
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