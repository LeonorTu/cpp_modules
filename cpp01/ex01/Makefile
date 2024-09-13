# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 17:12:40 by jtu               #+#    #+#              #
#    Updated: 2024/09/13 16:08:31 by jtu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

SRCS =	main.cpp \
		Zombie.cpp \
		zombieHorde.cpp

OBJS_DIR = ./obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))

CC = c++

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf *.dSYM
	@rm -rf .vscode
	@rm -rf .DS_Store

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
