.PHONY: libft all clean fclean re

NAME_PS = push_swap
NAME_CK = checker

SRCS =	push_swap.c \
		linked_list.c \
		base_operations.c \
		operations.c \
		solve.c \
		sort.c \
		check.c \
		lis.c \
		node.c \
		arg.c \
		select.c \
		util.c \
		test.c \

GCC_FLAG = -g -fsanitize=address
CC = gcc $(GCC_FLAG)

OBJS = $(SRCS:.c=.o)
OBJS_PS = $(SRCS_PS:.c=.o)
OBJS_CK = $(SRCS_CK:.c=.o)

all: $(NAME_PS) $(NAME_CK)

libft:
	make bonus -C Libft/

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME_PS): libft $(OBJS) $(OBJS_PS)
	$(CC) -o $@ $(OBJS) $(OBJS_PS) -Llibft -lft -I./

$(NAME_CK): libft $(OBJS) $(OBJS_CK)
	$(CC) -o $@ $(OBJS) $(OBJS_CK) -Llibft -lft -I./

clean:
	rm -f *.o
	make -C Libft/ clean

fclean: clean
	rm -f $(NAME_PS) $(NAME_CK)
	make -C libft/ fclean

re: fclean all
