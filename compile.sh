echo "Script for compile libftprintf"
make re
gcc libftprintf.a main.c libft/libft.a
make fclean