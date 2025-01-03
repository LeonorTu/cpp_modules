# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 17:12:40 by jtu               #+#    #+#              #
#    Updated: 2025/01/03 16:41:42 by jtu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FragTrap

SRCS =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp

OBJS_DIR = ./obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))

CC = c++

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf *.dSYM
	@rm -rf .vscode
	@rm -rf .DS_Store

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
