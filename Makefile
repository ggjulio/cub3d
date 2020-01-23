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
#    Updated: 2020/01/23 15:29:24 by juligonz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = Cub3D

LIB = ft mlx
FRAMEWORKS = OpenGL AppKit

SRC = main.c color.c vector.c application.c draw.c game.c camera.c fvector.c events.c parser.c
SRC := $(addprefix srcs/, $(SRC))

OBJ = $(SRC:.c=.o)

LFLAGS  = $(foreach framework, $(FRAMEWORKS),-framework $(framework))
LFLAGS += -L./lib $(foreach lib, $(LIB),-l$(lib))
IFLAGS  = -I./lib/libmlx -I./lib/libft -I./includes

CC = gcc
CFLAGS  = -Wall -Wextra -Werror -g
CFLAGS  += $(IFLAGS) #$(LFLAGS)

all: $(NAME)

libs: 
	@echo "$(_GREEN)Compiling libft.a ...$(_END)"
	@make -s -C lib/libft/
	@mv lib/libft/libft.a lib/
	@make -s fclean -s -C lib/libft/
	@echo "$(_RED)done ...$(_END)"
	@echo "\n"
	@echo "$(_GREEN)Compiling libmlx.a ...$(_END)"
	@make -s -i CFLAGS+=-w -C lib/libmlx/
	@mv lib/libmlx/libmlx.a lib/
	@make clean -s -i -C lib/libmlx/
	@echo "$(_RED)done ...$(_END)"

show:
	@echo "$(_CYAN)SRC    :$(_RED)  $(SRC)$(_END)"
	@echo "$(_CYAN)OBJ    :$(_RED)  $(OBJ)$(_END)"
	@echo "$(_CYAN)IFLAGS :$(_RED)  $(IFLAGS)$(_END)"
	@echo "$(_CYAN)LFLAGS :$(_RED)  $(LFLAGS)$(_END)"
	@echo "$(_CYAN)CFLAGS :$(_RED)  $(CFLAGS)$(_END)"

$(NAME): $(OBJ)
	@echo "$(_GREEN)Compiling ...$(_END)"
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^
	@echo "$(_GREEN)Compiled !$(_END)"

clean:
	@rm -f $(OBJ)
	@echo "$(_GREEN).o removed !$(_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(_GREEN)$(NAME) program removed !$(_END)"

bonus: $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus


#******************************************************************************#
#                                  REMINDER                                    #  
#******************************************************************************# \
                                                                                 \
                                                                                 \
Automatic variables :                                                            \
                                                                                 \
$@ : file name target. It's like $(NAME)                                         \
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