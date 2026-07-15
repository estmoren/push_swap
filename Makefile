NAME = push_swap

SRCS =	\
adaptive.c \
bench_helpers.c \
bench_text.c \
bench.c \
calc_disorder.c \
calc_median.c \
check_flags.c \
check_numbers.c \
chunk_sorting_helpers.c \
chunk_sorting.c \
complex_sort.c \
create_stack.c \
helpers.c \
join_args.c \
main.c \
push.c \
reverse_rotate.c \
rotate.c \
short_input.c \
simple_sort.c \
split.c \
swap.c \

OBJS = ${SRCS:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I .

%.o: %.c
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
