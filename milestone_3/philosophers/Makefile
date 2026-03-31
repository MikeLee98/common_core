# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mario <mario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/30 08:48:28 by mario             #+#    #+#              #
#    Updated: 2026/03/31 11:15:06 by mario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = -Iinc

SRCS = $(SRC_DIR)/philosophers.c
OBJS = $(OBJ_DIR)/philosophers.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJS)
	rm -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

