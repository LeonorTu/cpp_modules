# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtu <jtu@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 17:12:40 by jtu               #+#    #+#              #
#    Updated: 2024/07/02 15:52:50 by jtu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

OBJS = ${SRCS:.cpp=.o}

CC = g++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	@$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf *.dSYM
	@rm -rf .vscode
	@rm -rf .DS_Store

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re