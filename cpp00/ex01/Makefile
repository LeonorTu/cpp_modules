# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 17:12:40 by jtu               #+#    #+#              #
#    Updated: 2025/02/04 13:30:14 by jtu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRCS =	main.cpp \
		PhoneBook.cpp \
		Contact.cpp

OBJS_DIR = ./obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:%.cpp=%.o))

CC = c++

CCFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
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
