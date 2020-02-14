echo "Script for compile libftprintf"
make
gcc libftprintf.a main.c libft/libft.a
make fclean