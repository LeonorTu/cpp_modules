# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 17:12:40 by jtu               #+#    #+#              #
#    Updated: 2025/02/04 13:23:25 by jtu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ScavTrap

SRCS =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \

INCS = ClapTrap.hpp ScavTrap.hpp

OBJS_DIR = ./obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))

CC = c++

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp $(INCS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf *.dSYM
	@rm -rf .vscode
	@rm -rf .DS_Store

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
