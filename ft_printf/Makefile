# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 14:46:26 by mait-you          #+#    #+#              #
#    Updated: 2025/01/18 10:28:22 by mait-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= ft_printf.c ft_putchr.c ft_putstr.c ft_putadress.c \
	ft_putnbr.c ft_putunbr.c ft_puthexa.c

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libftprintf.a
AR			= ar rcs
RM			= rm -f

### Object Files
OBJS_DIR	:= ../obj/ft_printf
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.c ft_printf.h | $(OBJS_DIR) # order-only dependency
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@$(RM) $(OBJS) $(OBJBONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean
