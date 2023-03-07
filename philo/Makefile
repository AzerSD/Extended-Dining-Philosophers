# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asioud <asioud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 09:10:27 by asioud            #+#    #+#              #
#    Updated: 2023/03/07 09:19:49 by asioud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
CC			=	cc
RM			=	rm -f
LIBFT		= 	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	= 	-I ./includes/


src			=	parser.c \
				philo.c \
				time.c \

all:			$(NAME)

obj:
	mkdir -p obj

obj/%.o:	%.c | obj
	$(CC) $(CFLAGS) -c $(INCLUDES) $^ -o $@

clean:
	$(RM) philo

fclean:		clean
	$(RM) obj

re:	fclean all

./PHONY: all clean fclean re