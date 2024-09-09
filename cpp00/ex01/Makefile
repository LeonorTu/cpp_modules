# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 17:12:40 by jtu               #+#    #+#              #
#    Updated: 2024/09/09 17:13:30 by jtu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCS = phonebook.cpp\
		contact.cpp

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