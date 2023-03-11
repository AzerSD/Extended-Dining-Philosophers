
NAME		=	philo
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread
INCLUDES	=	-I./includes -I./lib
LIB_FILE	=	$(LIB_DIR)/libft.a


SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	includes
LIB_DIR		=	lib


SRC_FILES	=	$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES	=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))


all:	lib $(NAME)


$(NAME):	$(OBJ_FILES)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB_FILE) $(OBJ_FILES) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

lib:
	make -C $(LIB_DIR)

libclean:
	make -C $(LIB_DIR) clean

libfclean:	libclean
	@cd $(LIB_DIR) && rm -f libft.a

.PHONY: all clean fclean re lib libclean libfclean
