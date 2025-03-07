/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:18:53 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/17 18:20:13 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_new_nod(int data, t_stack *stack_a, t_stack *stack_b)
{
	t_node		*new_nod;

	new_nod = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new_nod)
	{
		free_nod(stack_a);
		free_nod(stack_b);
		write(2, "Error\n", 6);
		exit(1);
	}
	new_nod->num = data;
	return (new_nod);
}

t_top_five	*ft_new_top_five(t_stack *new_stk)
{
	t_top_five	*new_top_five;

	new_top_five = (t_top_five *)ft_calloc(1, sizeof(t_top_five));
	if (!new_top_five)
	{
		free_nod(new_stk);
		write(2, "Error\n", 6);
		exit(1);
	}
	return (new_top_five);
}

t_best_moves	*ft_new_best_moves(t_stack *stack_a, t_stack *stack_b)
{
	t_best_moves	*new_best_moves;

	new_best_moves = (t_best_moves *)ft_calloc(1, sizeof(t_best_moves));
	if (!new_best_moves)
	{
		free_nod(stack_a);
		free_nod(stack_b);
		write(2, "Error\n", 6);
		exit(1);
	}
	return (new_best_moves);
}

t_stack	*ft_new_stk(void)
{
	t_stack			*new_stk;

	new_stk = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new_stk)
		return (NULL);
	new_stk->top_five = ft_new_top_five(new_stk);
	return (new_stk);
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
	if (stack->size % 2 == 0)
		stack->middle_pos = (stack->size / 2);
	else if (stack->size % 2 != 0)
		stack->middle_pos = (stack->size / 2) + 1;
	new_nod->position = stack->size;
	return (0);
}
