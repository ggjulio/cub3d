#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 18:50:56 by juligonz          #+#    #+#              #
#    Updated: 2019/11/08 19:28:51 by juligonz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = cube3d

LDFLAGS = -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror 

SRCS = main.c

OBJ = $(SRCS:.c=.o)

all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) -o $@ $(LDFLAGS) $^
	$(info $(NAME) Compiled !)

clean:
	@rm -f $(OBJ)
	$(info .o removed !)

fclean: clean
	@rm -f $(NAME)
	$(info $(NAME) removed !)

bonus: $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus