NAME = push_swap

SRCS =	\

calc_disorder.c \
calc_median.c \
check_flags. \
check_numbers.c \
chunk_sorting_helpers.c \
chunk_sorting.c \
create_stack.c \
helpers.c \
main.c \
push.c \
reverse_rotate.c \
rotate.c \
simple_sort.c \
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
