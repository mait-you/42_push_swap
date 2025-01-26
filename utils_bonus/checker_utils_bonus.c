/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 08:45:17 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/26 09:30:39 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	ft_is_stack_sorted(t_stack *stack_a)
{
	t_node	*tmp;

	tmp = stack_a->top;
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->num > tmp->next->num)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_check_instruct(t_instruct *instruct)
{
	int		instruct_len;
	char	*instruct_chr;

	instruct_chr = instruct->instruct;
	instruct_len = ft_strlen(instruct_chr);
	if (instruct_len != 2 && instruct_len != 3)
		return (1);
	while (*instruct_chr)
	{
		if (!ft_strchr(RULES_LETTERS, *instruct_chr))
			return (1);
		instruct_chr++;
	}
	return (0);
}

int	ft_add_nod_to_stk(t_stack *stack, t_node *new_nod)
{
	if (!stack || !new_nod)
		return (1);
	if (!stack->top)
	{
		stack->top = new_nod;
		stack->bottom = new_nod;
	}
	else
	{
		stack->bottom->next = new_nod;
		new_nod->prev = stack->bottom;
		stack->bottom = new_nod;
	}
	stack->size++;
	return (0);
}

int	aplyy_instructions(char *instruct, t_stack *stack_a, \
	t_stack *stack_b)
{
	if (!ft_strncmp(instruct, "pb", 3))
		ft_pb(stack_a, stack_b, PRINT);
	else if (!ft_strncmp(instruct, "pa", 3))
		ft_pa(stack_b, stack_a, PRINT);
	else if (!ft_strncmp(instruct, "sa", 3))
		ft_sa(stack_a, PRINT);
	else if (!ft_strncmp(instruct, "sb", 3))
		ft_sb(stack_b, PRINT);
	else if (!ft_strncmp(instruct, "ss", 3))
		ft_ss(stack_a, stack_b);
	else if (!ft_strncmp(instruct, "ra", 3))
		ft_ra(stack_a, PRINT);
	else if (!ft_strncmp(instruct, "rb", 3))
		ft_rb(stack_b, PRINT);
	else if (!ft_strncmp(instruct, "rr", 3))
		ft_rr(stack_a, stack_b);
	else if (!ft_strncmp(instruct, "rra", 4))
		ft_rra(stack_a, PRINT);
	else if (!ft_strncmp(instruct, "rrb", 4))
		ft_rrb(stack_b, PRINT);
	else if (!ft_strncmp(instruct, "rrr", 4))
		ft_rrr(stack_a, stack_b);
	return (0);
}
