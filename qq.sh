#gcc *.c Libft/*.c
gcc -g -fsanitize=address  *.c Libft/*.c
./a.out 0  2 3 4 5 1
