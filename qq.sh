#gcc *.c Libft/*.c
gcc -g -fsanitize=address  *.c Libft/*.c
./a.out 5 10 4 3 20 2 1 0
