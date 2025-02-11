/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_b_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:21:55 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/25 10:01:27 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	ft_rrb(t_stack *stack_b, int print)
{
	t_node	*tmp_1_nod_a;
	t_node	*tmp_2_nod_a;

	if (stack_b->size < 2)
		return (1);
	tmp_1_nod_a = stack_b->bottom;
	tmp_2_nod_a = stack_b->bottom->prev;
	stack_b->bottom = tmp_2_nod_a;
	stack_b->bottom->next = NULL;
	tmp_1_nod_a->prev = NULL;
	tmp_1_nod_a->next = stack_b->top;
	stack_b->top->prev = tmp_1_nod_a;
	stack_b->top = tmp_1_nod_a;
	if (print)
		write(1, "rrb\n", 4);
	return (0);
}
