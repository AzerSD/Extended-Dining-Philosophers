# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asioud <asioud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 09:10:27 by asioud            #+#    #+#              #
#    Updated: 2023/03/07 09:38:28 by asioud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CC			=	cc
RM			=	rm -f
LIBFT		= 	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	= 	-I ./includes/
LIBFT_H		=	./lib/libft.h


src			=	parser.c \
				philo.c \
				time.c \

all:			$(NAME)

obj:
	mkdir -p obj

obj/%.o:	%.c | obj
	cd lib && make
	$(CC) $(CFLAGS) -c $(INCLUDES) $^ -o $@

clean:
	cd lib && make clean
	$(RM) philo

fclean:		clean
	cd lib && make fclean
	$(RM) obj

re:	fclean all

./PHONY: all clean fclean re