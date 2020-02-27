# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamather <tamather@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 01:14:07 by tamather          #+#    #+#              #
#    Updated: 2020/02/26 16:54:48 by tamather         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = printf.c parsing.c ft_display.c utils.c
SRCDIR = src
OBJDIR = objs
DEPDIR = deps
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DFLAGS= -MP -MMD -MF $*.d -MT '$@'
NAME = libftprintf.a 

OBJS := $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS := $(SRCS:.c=.d)

$(NAME):		$(OBJDIR) $(OBJS)
			@make -C libft
			ar rcs $(NAME) $(OBJS) libft/ft_isdigit.o libft/ft_atoi.o libft/ft_strlen.o libft/ft_itoa.o libft/ft_strlcpy.o libft/ft_putnbr_fd.o libft/ft_putchar_fd.o libft/ft_bzero.o libft/ft_memset.o

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
			$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

all:		$(NAME)

clean:
			@rm -rf 	$(OBJDIR) $(DEPDIR)
			@make -C libft clean

$(OBJDIR):
			mkdir $@

fclean:		clean
			@rm -f	$(NAME) $(DEPS)
			@make -C libft fclean

re: fclean all

-include $(DEPS)