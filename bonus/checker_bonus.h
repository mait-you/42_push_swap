/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:43:30 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/11 09:13:35 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

// includes
# include "../lib/libft.h"
# include <unistd.h>
# include <limits.h>

# ifndef PRINT
#  define PRINT 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# ifndef RULES_LETTERS
#  define RULES_LETTERS "prsab"
# endif

// instruct struct
typedef struct s_instruct
{
	char				*instruct;
	struct s_instruct	*next;
}					t_instruct;

// node struct 
typedef struct s_node
{
	int					num;
	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

// stack struct
typedef struct s_stack
{
	int					size;
	t_node				*top;
	t_node				*bottom;
}						t_stack;

// utility function declarations
char		*get_next_line(int fd);
void		free_nod(t_stack *stack);
void		free_args(char **args);
void		free_instructions(t_instruct **instructions);
int			ft_is_stack_sorted(t_stack *stack_a);
t_node		*ft_new_nod(int data);
t_stack		*ft_new_stk(void);
t_instruct	*ft_new_instruct(char *instruct);
int			ft_check_instruct(t_instruct *instruct);
int			ft_add_nod_to_stk(t_stack *stack, t_node *new_nod);
int			add_new_instruct(t_instruct **instructions, \
	t_instruct *new_instruct);
void		error_cleanup(t_stack *stack_a, t_stack *stack_b, \
	t_instruct **instructions);
int			aplyy_instructions(char *instruct, t_stack *stack_a, \
	t_stack *stack_b);

// rules declarations
int			ft_pa(t_stack *stack_b, t_stack *stack_a, int print);
int			ft_pb(t_stack *stack_a, t_stack *stack_b, int print);
int			ft_rra(t_stack *stack_a, int print);
int			ft_rrb(t_stack *stack_b, int print);
int			ft_rrr(t_stack *stack_a, t_stack *stack_b);
int			ft_sa(t_stack *stack_a, int print);
int			ft_sb(t_stack *stack_b, int print);
int			ft_ss(t_stack *stack_a, t_stack *stack_b);
int			ft_ra(t_stack *stack_a, int print);
int			ft_rb(t_stack *stack_b, int print);
int			ft_rr(t_stack *stack_a, t_stack *stack_b);

#endif
