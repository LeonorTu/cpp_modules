# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 17:12:40 by jtu               #+#    #+#              #
#    Updated: 2024/05/30 17:21:16 by jtu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

OBJS = ${SRCS:.c=.o}

FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	@cc $(CFLAGS) $^ -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf *.dSYM
	@rm -rf .vscode
	@rm -rf .DS_Store

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re