# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 01:28:20 by mkazuhik          #+#    #+#              #
#    Updated: 2025/08/08 12:17:27 by mkazuhik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRCS		= src/main.c src/utils.c src/find_func.c src/open1.c src/open2.c src/set.c src/sort.c

OBJS		= ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all:		${NAME}

${NAME}:	${OBJS}
			${MAKE} -C libft
			${CC} ${OBJS} libft/libft.a -o ${NAME}

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			${RM} ${OBJS}
			${MAKE} -C libft clean

fclean:		clean
			${RM} ${NAME}
			${RM} libft/libft.a


re:			fclean all

.PHONY:		all clean fclean re