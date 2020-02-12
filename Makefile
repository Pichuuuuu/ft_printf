# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tamather <tamather@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 01:14:07 by tamather          #+#    #+#              #
#    Updated: 2020/02/09 02:04:59 by tamather         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = printf.c
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
			ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
			$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

all:		$(NAME)

clean:
			rm -rf 	$(OBJDIR) $(DEPDIR)

$(OBJDIR):
			mkdir $@

fclean:		clean
			rm -f	$(NAME) $(DEPS)

re: fclean all

-include $(DEPS)