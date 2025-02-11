/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:54:37 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/21 15:54:22 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sa(t_stack *stack_a, int print)
{
	t_node	*tmp_1_nod_a;
	t_node	*tmp_2_nod_a;

	if (stack_a->size < 2)
		return (1);
	tmp_1_nod_a = stack_a->top;
	tmp_2_nod_a = tmp_1_nod_a->next;
	stack_a->top = tmp_2_nod_a;
	tmp_2_nod_a->prev = NULL;
	tmp_1_nod_a->next = tmp_2_nod_a->next;
	if (tmp_2_nod_a->next)
		tmp_2_nod_a->next->prev = tmp_1_nod_a;
	tmp_2_nod_a->next = tmp_1_nod_a;
	tmp_1_nod_a->prev = tmp_2_nod_a;
	if (stack_a->size == 2)
		stack_a->bottom = tmp_1_nod_a;
	if (print)
		write(1, "sa\n", 3);
	return (ft_get_stk_info(stack_a));
}
