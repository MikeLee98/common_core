# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mario <mario@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/30 08:48:28 by mario             #+#    #+#              #
#    Updated: 2026/04/10 14:05:23 by mario            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC_DIR = src
OBJ_DIR = obj
INCLUDES = -Iinc

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/monitor.c $(SRC_DIR)/routine.c $(SRC_DIR)/utils.c $(SRC_DIR)/parser.c $(SRC_DIR)/states.c $(SRC_DIR)/cleanup.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/monitor.o $(OBJ_DIR)/routine.o $(OBJ_DIR)/utils.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/states.o $(OBJ_DIR)/cleanup.o

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
