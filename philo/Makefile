# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asioud <asioud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 09:10:27 by asioud            #+#    #+#              #
#    Updated: 2023/03/07 11:08:19 by asioud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project settings
TARGET = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -I./lib -I./includes
LIB_FILE	= $(LIB_DIR)/libft.a

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIB_DIR = lib


SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))


all: lib $(TARGET)


$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $(LIB_FILE) $< -o $@ $(LDFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


 
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

lib:
	make -C $(LIB_DIR)

libclean:
	make -C $(LIB_DIR) clean

.PHONY: all clean fclean re lib libclean
