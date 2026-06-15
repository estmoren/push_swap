# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumacko <lumacko@student.42malaga.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 12:25:57 by lumacko           #+#    #+#              #
#    Updated: 2026/06/15 12:25:57 by lumacko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

// SRC =

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
