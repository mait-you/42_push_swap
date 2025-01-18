/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:58:18 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/17 21:54:14 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_pa(t_stack *stack_b, t_stack *stack_a, int print)
{
	t_node	*tmp_nod_b;

	if (stack_b->size <= 0)
		return (1);
	tmp_nod_b = stack_b->top;
	stack_b->top = stack_b->top->next;
	if (stack_b->top)
		stack_b->top->prev = NULL;
	else
		stack_b->bottom = NULL;
	tmp_nod_b->next = stack_a->top;
	if (stack_a->top)
		stack_a->top->prev = tmp_nod_b;
	else
		stack_a->bottom = tmp_nod_b;
	stack_a->top = tmp_nod_b;
	tmp_nod_b->prev = NULL;
	stack_b->size--;
	stack_a->size++;
	if (print)
		ft_printf("pa\n");
	return (ft_get_stk_info(stack_a) || ft_get_stk_info(stack_b));
}
