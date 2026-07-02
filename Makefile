NAME = push_swap

SRCS =	\

helpers.c \
create_stack.c \
calc_disorder.c \
check_numbers.c \
check_flags. \
main.c \
push.c \
reverse_rotate.c \
rotate.c \
swap.c \


OBJS = ${SRCS:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I .

%.O: %.c:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
