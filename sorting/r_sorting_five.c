/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_sorting_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:47:59 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/22 10:30:20 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_r_sort_three(t_stack *stack_b)
{
	if (stack_b->top->num < stack_b->top->next->num
		&& stack_b->top->num < stack_b->top->next->next->num)
		ft_rb(stack_b, PRINT);
	else if (stack_b->top->next->num < stack_b->top->num
		&& stack_b->top->next->num < stack_b->top->next->next->num)
		ft_rrb(stack_b, PRINT);
	if (stack_b->top->num < stack_b->top->next->num)
		ft_sb(stack_b, PRINT);
	return (1);
}

int	ft_r_sort_four(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*biggest_nod;
	int		i;

	biggest_nod = ft_get_biggest_nod(stack_b);
	i = biggest_nod->price;
	if (biggest_nod->direction == -1)
		while (i-- > 0)
			ft_rrb(stack_b, PRINT);
	else if (biggest_nod->direction == 1)
		while (i-- > 0)
			ft_rb(stack_b, PRINT);
	ft_pa(stack_b, stack_a, PRINT);
	ft_r_sort_three(stack_b);
	ft_pb(stack_a, stack_b, PRINT);
	return (0);
}

int	ft_r_sort_five(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*biggest_nod;
	int		i;

	biggest_nod = ft_get_biggest_nod(stack_b);
	i = biggest_nod->price;
	if (biggest_nod->direction == -1)
		while (i-- > 0)
			ft_rrb(stack_b, PRINT);
	else if (biggest_nod->direction == 1)
		while (i-- > 0)
			ft_rb(stack_b, PRINT);
	ft_pa(stack_b, stack_a, PRINT);
	ft_r_sort_four(stack_b, stack_a);
	ft_pb(stack_a, stack_b, PRINT);
	return (0);
}

int	r_sort_five_or_less(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_b->size == 1)
		return (0);
	if (stack_b->size == 2)
	{
		if (stack_b->top->num < stack_b->top->next->num)
			return (ft_sb(stack_b, PRINT));
	}
	if (stack_b->size == 3)
		return (ft_r_sort_three(stack_b));
	if (stack_b->size == 4)
		return (ft_r_sort_four(stack_b, stack_a));
	return (ft_r_sort_five(stack_b, stack_a));
}
