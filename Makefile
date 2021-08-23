.PHONY: libft all clean fclean re

NAME_PS = push_swap

SRCS =	push_swap.c \
		linked_list.c \
		base_operations.c \
		operations.c \
		operations_double.c \
		solve.c \
		sort.c \
		check.c \
		lis.c \
		node.c \
		arg.c \
		select.c \
		base_bf.c \
		base_func2.c \
		util.c \
		test.c \
		bruteforce.c \
		calc_bf.c 

GCC_FLAG = -g -fsanitize=address
CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)
OBJS_PS = $(SRCS_PS:.c=.o)

all: $(NAME_PS)

libft:
	make bonus -C Libft/

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME_PS): libft $(OBJS) $(OBJS_PS)
	$(CC) -o $@ $(OBJS) $(OBJS_PS) -Llibft -lft -I./


clean:
	rm -f *.o
	make -C Libft/ clean

fclean: clean
	rm -f $(NAME_PS) $(NAME_CK)
	make -C Libft/ fclean

re: fclean all
