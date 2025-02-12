/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:02:48 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/11 14:19:33 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_node	*tmp_nod_a;

	if (stack_a->size == 0)
		return (1);
	tmp_nod_a = stack_a->top;
	stack_a->top = stack_a->top->next;
	if (stack_a->top)
		stack_a->top->prev = NULL;
	else
		stack_a->bottom = NULL;
	tmp_nod_a->next = stack_b->top;
	if (stack_b->top)
		stack_b->top->prev = tmp_nod_a;
	else
		stack_b->bottom = tmp_nod_a;
	stack_b->top = tmp_nod_a;
	tmp_nod_a->prev = NULL;
	stack_a->size--;
	stack_b->size++;
	if (print)
		write(1, "pb\n", 3);
	return (ft_get_stk_info(stack_a) || ft_get_stk_info(stack_b));
}
