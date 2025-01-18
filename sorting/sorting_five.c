/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 08:47:06 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/17 21:53:45 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sort_three(t_stack *stack_a)
{
	if (stack_a->top->num > stack_a->top->next->num
		&& stack_a->top->num > stack_a->top->next->next->num)
		ft_ra(stack_a, PRINT);
	else if (stack_a->top->next->num > stack_a->top->num
		&& stack_a->top->next->num > stack_a->top->next->next->num)
		ft_rra(stack_a, PRINT);
	if (stack_a->top->num > stack_a->top->next->num)
		ft_sa(stack_a, PRINT);
	return (1);
}

int	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest_nod;
	int		i;

	smallest_nod = ft_get_smallest_nod(stack_a);
	i = smallest_nod->price;
	if (smallest_nod->direction == -1)
		while (i-- > 0)
			ft_rra(stack_a, PRINT);
	else if (smallest_nod->direction == 1)
		while (i-- > 0)
			ft_ra(stack_a, PRINT);
	ft_pb(stack_a, stack_b, PRINT);
	ft_sort_three(stack_a);
	ft_pa(stack_b, stack_a, PRINT);
	return (0);
}

int	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*smallest_nod;
	int		middle;
	int		i;

	middle = (stack_a->size / 2) + 1;
	smallest_nod = ft_get_smallest_nod(stack_a);
	i = smallest_nod->price;
	if (smallest_nod->direction == -1)
		while (i-- > 0)
			ft_rra(stack_a, PRINT);
	else if (smallest_nod->direction == 1)
		while (i-- > 0)
			ft_ra(stack_a, PRINT);
	ft_pb(stack_a, stack_b, PRINT);
	ft_sort_four(stack_a, stack_b);
	ft_pa(stack_b, stack_a, PRINT);
	return (0);
}

int	sort_five_or_less(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		return (ft_sa(stack_a, PRINT));
	if (stack_a->size == 3)
		return (ft_sort_three(stack_a));
	if (stack_a->size == 4)
		return (ft_sort_four(stack_a, stack_b));
	return (ft_sort_five(stack_a, stack_b));
}
