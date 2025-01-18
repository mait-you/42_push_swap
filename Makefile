# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 20:09:42 by mait-you          #+#    #+#              #
#    Updated: 2025/01/18 10:30:08 by mait-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Compiler and Flags
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -rf

### Executable Name
NAME		:= push_swap

### Libraries
LIBFT_DIR	:= libft
PRINTF_DIR	:= ft_printf
LIBFT		:= $(LIBFT_DIR)/libft.a
FT_PRINTF	:= $(PRINTF_DIR)/libftprintf.a

### Source Files
RULES		:= rules/ft_push_a.c rules/ft_push_b.c \
			rules/ft_swap_a.c rules/ft_swap_b.c rules/ft_swap_a_b.c \
			rules/ft_rotate_a.c rules/ft_rotate_b.c rules/ft_rotate_a_b.c \
			rules/ft_reverse_rotate_a.c rules/ft_reverse_rotate_b.c \
			rules/ft_reverse_rotate_a_b.c

UTILS		:= utils/p_s_utils.c utils/p_s_top_five.c utils/p_s_new.c \
			utils/p_s_get_utils.c utils/p_s_get_2_utils.c utils/p_s_bottom_five.c

SORTING		:= sorting/sorting_five.c sorting/r_sorting_five.c

SRCS		:= push_swap.c algorithm.c $(RULES) $(UTILS) $(SORTING)

### Object Files
OBJS_DIR	:= obj
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)

### Colors and Formatting
RESET		:= \033[0m
BLACK		:= \033[30m
RED			:= \033[31m
GREEN		:= \033[32m
YELLOW		:= \033[33m
BLUE		:= \033[34m
PURPLE		:= \033[35m
CYAN		:= \033[36m
WHITE		:= \033[37m
BOLD		:= \033[1m
UP			:= \033[F

### Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "$(RED)$(BOLD)$(NAME) $(GREEN)compiled successfully!$(RESET)"

$(LIBFT):
	@echo "$(CYAN)Building libft ...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(CYAN)╰─ Built $(PURPLE)$(BOLD)$(LIBFT)$(RESET)"

$(FT_PRINTF):
	@echo "$(CYAN)Building ft_printf ...$(RESET)"
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "$(CYAN)╰─ Built $(PURPLE)$(BOLD)$(FT_PRINTF)$(RESET)"

$(OBJS_DIR)/%.o: %.c push_swap.h | $(OBJS_DIR) # order-only dependency
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling: $(WHITE)$<$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(RM) $(OBJS_DIR)
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@$(RM) $(NAME)
	@echo "$(RED)$(UP)Cleaned object files and $(PURPLE)$(BOLD)$(LIBFT)$(RESET)$(RED), \
	$(PURPLE)$(BOLD)$(FT_PRINTF)$(RESET)$(RED), $(RED)$(BOLD)$(NAME)$(RESET)"

re: fclean all

.PHONY: clean
