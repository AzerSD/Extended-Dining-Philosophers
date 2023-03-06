
NAME		=	philo
CC			=	cc
RM			=	rm -rf
LIBFT		= 	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror

src			=	parser.c \
				philo.c \

OBJ			=	$(SRC=.c:.o)

NAME	:	$(OBJ)

$(OBJ) : $(SRC)
