/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:55:56 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/21 15:54:31 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sb(t_stack *stack_b, int print)
{
	t_node	*tmp_1_nod_b;
	t_node	*tmp_2_nod_b;

	if (stack_b->size < 2)
		return (1);
	tmp_1_nod_b = stack_b->top;
	tmp_2_nod_b = tmp_1_nod_b->next;
	stack_b->top = tmp_2_nod_b;
	tmp_2_nod_b->prev = NULL;
	tmp_1_nod_b->next = tmp_2_nod_b->next;
	if (tmp_2_nod_b->next)
		tmp_2_nod_b->next->prev = tmp_1_nod_b;
	tmp_2_nod_b->next = tmp_1_nod_b;
	tmp_1_nod_b->prev = tmp_2_nod_b;
	if (stack_b->size == 2)
		stack_b->bottom = tmp_1_nod_b;
	if (print)
		write(1, "sb\n", 3);
	return (ft_get_stk_info(stack_b));
}
