/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:48:13 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/18 11:10:32 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int smart_rotate_a(t_stack *stack_a, int direction, int price)
{
	if (direction == -1)
		while (price-- > 0)
			ft_rra(stack_a, PRINT);
	else if (direction == 1)
		while (price-- > 0)
			ft_ra(stack_a, PRINT);
	return (0);
}

int ft_smart_move(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*top_b_nod;
	t_node	*bot_b_nod;
	int		target_price;
	int		target_direction;

	top_b_nod = stack_b->top;
	bot_b_nod = stack_b->bottom;
	target_price = top_b_nod->a_target_nod->price;
	target_direction = top_b_nod->a_target_nod->direction;
	if (top_b_nod->best_move == 0)
		return (smart_rotate_a(stack_a, target_direction, target_price));
	if (bot_b_nod->best_move == 0)
		return (smart_rotate_a(stack_a, target_direction, target_price));
	smart_rotate_a(stack_a, target_direction, target_price);
	return (0);
}


int ft_push_middle(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*middle_nod;
	int		i;
	
	middle_nod = ft_get_middle_nod(stack_a);
	i = middle_nod->price;
	if (middle_nod->direction == -1)
		while (i-- > 0)
			ft_rra(stack_a, PRINT);
	else if (middle_nod->direction == 1)
		while (i-- > 0)
			ft_ra(stack_a, PRINT);
	return (ft_pb(stack_a, stack_b, PRINT));
}

// Quick Sort
int push_quick_sort_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*pivot;

	ft_memset(stack_a->top_five, 0, sizeof(t_top_five));
	ft_get_top_5_nod(stack_a);
	ft_memset(stack_a->bottom_five, 0, sizeof(t_bottom_five));
	ft_get_bottom_5_nod(stack_a);
	ft_push_middle(stack_a, stack_b);
	pivot = stack_b->top;
	while(stack_a->size > 5)
	{
		if (ft_is_top_5(stack_a, stack_a->top))
		{
			ft_pb(stack_a, stack_b, PRINT);
			if (pivot->num < stack_b->top->num)
				ft_rb(stack_b, PRINT);
		}
		else
			ft_ra(stack_a, PRINT);
	}
	if (stack_a->size == 5)
			sort_five_or_less(stack_a, stack_b);
	return (0);
}

int push_quick_sort_a(t_stack *stack_b, t_stack *stack_a)
{
	while (stack_b->size > 5)
	{
		if (ft_is_bottom_5(stack_b, stack_b->top))
		{
			print_stack("stack_a", stack_a);
			print_stack__("stack_b", stack_b);
			ft_update_target(stack_a, stack_b);
			ft_smart_move(stack_b, stack_a);
			ft_pa(stack_b, stack_a, PRINT);
		}
		else if (ft_is_bottom_5(stack_b, stack_b->top->next) && 
			stack_b->top->next->a_target_nod->price != 0)
			ft_rr(stack_a, stack_b);
		else 
			ft_rb(stack_b, PRINT);
	}
	if (!ft_is_stack_sorted(stack_a))
		sort_a(stack_a);
	if (stack_b->size == 5)
	{
		ft_r_sort_five(stack_b, stack_a);
		while (stack_b->size > 0)
			ft_pa(stack_b, stack_a, PRINT);
	}
	return (0);
}

// Main sorting function
int	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size <= 1)
		return (1);
	if (stack_a->size <= 5)
		return (sort_five_or_less(stack_a, stack_b));
	push_quick_sort_b(stack_a, stack_b);
	ft_memset(stack_b->top_five, 0, sizeof(t_top_five));
	ft_get_top_5_nod(stack_b);
	ft_memset(stack_b->bottom_five, 0, sizeof(t_bottom_five));
	ft_get_bottom_5_nod(stack_b);
	ft_update_target(stack_a, stack_b);
	push_quick_sort_a(stack_b, stack_a);
	return (0);
}

