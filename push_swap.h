/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:43:30 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/21 10:45:05 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// includes
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

# ifndef PRINT
#  define PRINT 1
# endif

typedef struct s_best_moves
{
	int			ra_count;
	int			rb_count;
	int			rr_count;
	int			rra_count;
	int			rrb_count;
	int			rrr_count;
	int			total_cost;
}				t_best_moves;

// node struct 
typedef struct s_node
{
	int				num;
	int				position;
	int				price;
	int				direction;
	t_best_moves	*best_move;
	// struct s_node	*f_target_nod;
	struct s_node	*a_target_nod;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// top five numbers in stack
typedef struct s_top_five
{
	t_node			*one;
	t_node			*two;
	t_node			*three;
	t_node			*four;
	t_node			*five;
}					t_top_five;


// top five numbers in stack
// typedef struct s_bottom_five
// {
// 	t_node			*one;
// 	t_node			*two;
// 	t_node			*three;
// 	t_node			*four;
// 	t_node			*five;
// }					t_bottom_five;

// stack struct
typedef struct s_stack
{
	int				size;
	int				middle_pos;
	t_top_five		*top_five;
	t_node			*top;
	t_node			*bottom;
}					t_stack;

// utility function declarations
void			free_nod(t_stack *stack);
void			free_args(char **args);
t_node			*ft_new_nod(int data);
t_top_five		*ft_new_top_five(void);
// t_bottom_five	*ft_new_bottom_five(void);
t_best_moves	*ft_new_best_moves(void);
t_stack			*ft_new_stk(void);
int				ft_add_nod_to_stk(t_stack *stack, t_node *new_nod);
int				ft_is_stack_sorted(t_stack *stack_a);
int				ft_get_stk_info(t_stack *stack);
t_node			*ft_get_smallest_nod(t_stack *stack);
t_node			*ft_get_biggest_nod(t_stack *stack);
t_node			*ft_get_middle_nod(t_stack *stack);
int				ft_get_top_5_nod(t_stack *stack);
int				ft_is_top_5(t_stack *stack, t_node *nod);
// int				ft_get_bottom_5_nod(t_stack *stack);
// int				ft_is_bottom_5(t_stack *stack, t_node *nod);
int				ft_get_f_target(t_node *tmp_nod, t_stack *stack_b, \
								t_stack *stack_a);
int				ft_get_a_target(t_node *tmp_nod, t_stack *stack_a);
int				ft_update_target(t_stack *stack_a, t_stack *stack_b);
int				sort_a(t_stack *stack_a);
int				double_r(t_best_moves *bm);

void			print_sort_stack(const char *stack_name, t_stack *stack);
void			print_stack(const char *stack_name, t_stack *stack);
void			print_stack__(const char *stack_name, t_stack *stack);

// sorting
int				ft_sort_three(t_stack *stack_a);
int				ft_sort_four(t_stack *stack_a, t_stack *stack_b);
int				ft_sort_five(t_stack *stack_a, t_stack *stack_b);
int				sort_five_or_less(t_stack *stack_a, t_stack *stack_b);
int				ft_r_sort_three(t_stack *stack_b);
int				ft_r_sort_four(t_stack *stack_b, t_stack *stack_a);
int				ft_r_sort_five(t_stack *stack_b, t_stack *stack_a);

// rules declarations
int				ft_pa(t_stack *stack_b, t_stack *stack_a, int print);
int				ft_pb(t_stack *stack_a, t_stack *stack_b, int print);
int				ft_rra(t_stack *stack_a, int print);
int				ft_rrb(t_stack *stack_b, int print);
int				ft_rrr(t_stack *stack_a, t_stack *stack_b);
int				ft_sa(t_stack *stack_a, int print);
int				ft_sb(t_stack *stack_b, int print);
int				ft_ss(t_stack *stack_a, t_stack *stack_b);
int				ft_ra(t_stack *stack_a, int print);
int				ft_rb(t_stack *stack_b, int print);
int				ft_rr(t_stack *stack_a, t_stack *stack_b);

// sorting algorithm function declarations
int				sort_stack(t_stack *stack_a, t_stack *stack_b);

#endif
