echo "Script for compile libftprintf"
make
gcc libftprintf.a main.c
make fclean