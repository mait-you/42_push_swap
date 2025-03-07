# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 20:09:42 by mait-you          #+#    #+#              #
#    Updated: 2025/02/17 09:31:29 by mait-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### Compiler and Flags
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -rf
AR			:= ar rcs

### dirs
SRC_DIR		:= mandatory/srcs
UTILS_DIR	:= mandatory/utils
RULES_DIR	:= mandatory/rules
SORTING_DIR	:= mandatory/sorting
BONU_S_DIR	:= bonus/srcs_bonus
UTILS_B_DIR	:= bonus/utils_bonus
RULES_B_DIR	:= bonus/rules_bonus
LIBFT_DIR	:= lib
OBJS_DIR	:= obj

### Executable Name
NAME		:= push_swap
BONUS		:= checker

LIBFT		:= $(LIBFT_DIR)/libft.a

### Source Files
LIBFT_SRCS	:= $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_memset.c $(LIBFT_DIR)/ft_strncmp.c $(LIBFT_DIR)/ft_atoi.c \
			$(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_substr.c $(LIBFT_DIR)/ft_split.c \
			$(LIBFT_DIR)/ft_strcspn.c $(LIBFT_DIR)/ft_strchr.c $(LIBFT_DIR)/ft_strjoin.c

RULES		:= $(RULES_DIR)/ft_push_a.c $(RULES_DIR)/ft_push_b.c \
			$(RULES_DIR)/ft_swap_a.c $(RULES_DIR)/ft_swap_b.c $(RULES_DIR)/ft_swap_a_b.c \
			$(RULES_DIR)/ft_rotate_a.c $(RULES_DIR)/ft_rotate_b.c $(RULES_DIR)/ft_rotate_a_b.c \
			$(RULES_DIR)/ft_reverse_rotate_a.c $(RULES_DIR)/ft_reverse_rotate_b.c \
			$(RULES_DIR)/ft_reverse_rotate_a_b.c

UTILS		:= $(UTILS_DIR)/p_s_utils.c $(UTILS_DIR)/p_s_utils_2.c $(UTILS_DIR)/p_s_top_five.c \
			$(UTILS_DIR)/p_s_new.c $(UTILS_DIR)/p_s_get_utils.c $(UTILS_DIR)/p_s_get_2_utils.c 

SORTING		:= $(SORTING_DIR)/sorting_five.c $(SORTING_DIR)/r_sorting_five.c $(SORTING_DIR)/sort_ten.c

SRCS		:= $(SRC_DIR)/push_swap.c $(SRC_DIR)/algorithm.c $(RULES) $(UTILS) $(SORTING)

BONUS_RULES	:= $(RULES_B_DIR)/ft_push_a_bonus.c $(RULES_B_DIR)/ft_push_b_bonus.c \
			$(RULES_B_DIR)/ft_swap_a_bonus.c $(RULES_B_DIR)/ft_swap_b_bonus.c $(RULES_B_DIR)/ft_swap_a_b_bonus.c \
			$(RULES_B_DIR)/ft_rotate_a_bonus.c $(RULES_B_DIR)/ft_rotate_b_bonus.c $(RULES_B_DIR)/ft_rotate_a_b_bonus.c \
			$(RULES_B_DIR)/ft_reverse_rotate_a_bonus.c $(RULES_B_DIR)/ft_reverse_rotate_b_bonus.c \
			$(RULES_B_DIR)/ft_reverse_rotate_a_b_bonus.c

BONUS_UTILS	:= $(UTILS_B_DIR)/checker_utils_bonus.c $(UTILS_B_DIR)/checker_cleanup_bonus.c $(UTILS_B_DIR)/checker_new_bonus.c $(UTILS_B_DIR)/get_next_line_bonus.c

BONUS_SRCS	:= $(BONU_S_DIR)/checker_bonus.c $(BONUS_UTILS) $(BONUS_RULES)

### Object Files
OBJS		:= $(SRCS:%.c=$(OBJS_DIR)/%.o)
LIBFT_OBJS	:= $(LIBFT_SRCS:%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS	:= $(BONUS_SRCS:%.c=$(OBJS_DIR)/%.o)

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

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(RED)$(BOLD)$(NAME) $(GREEN)compiled successfully!$(RESET)"

$(LIBFT): $(LIBFT_OBJS)
	@$(AR) $(LIBFT) $(LIBFT_OBJS)
	@echo "$(CYAN)Building libft ...$(RESET)"
	@echo "$(CYAN)╚═ Built $(PURPLE)$(BOLD)$(LIBFT)$(RESET)"

# libft Object file compilation rules
$(OBJS_DIR)/$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c $(LIBFT_DIR)/libft.h | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling: $(WHITE)$<$(RESET)"

# mandatory Object file compilation rules
$(OBJS_DIR)/mandatory/%.o: mandatory/%.c mandatory/push_swap.h $(LIBFT_DIR)/libft.h | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling: $(WHITE)$<$(RESET)"

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)
	@echo "$(RED)$(BOLD)$(BONUS) $(GREEN)compiled successfully!$(RESET)"

# bonus Object file compilation rules
$(OBJS_DIR)/bonus/%.o: bonus/%.c bonus/checker_bonus.h $(LIBFT_DIR)/libft.h | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compiling: $(WHITE)$<$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@$(RM) $(OBJS_DIR) $(LIBFT)
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(BONUS)
	@echo "$(RED)$(UP)Cleaned object files and $(PURPLE)$(BOLD)$(LIBFT)$(RESET)$(RED), $(RED)$(BOLD)$(NAME)$(RESET)"

re: fclean all

.PHONY: clean
