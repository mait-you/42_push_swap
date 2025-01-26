/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_a_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:22:02 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/25 10:01:25 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	ft_rra(t_stack *stack_a, int print)
{
	t_node	*tmp_1_nod_a;
	t_node	*tmp_2_nod_a;

	if (stack_a->size < 2)
		return (1);
	tmp_1_nod_a = stack_a->bottom;
	tmp_2_nod_a = stack_a->bottom->prev;
	stack_a->bottom = tmp_2_nod_a;
	stack_a->bottom->next = NULL;
	tmp_1_nod_a->prev = NULL;
	tmp_1_nod_a->next = stack_a->top;
	stack_a->top->prev = tmp_1_nod_a;
	stack_a->top = tmp_1_nod_a;
	if (print)
		write(1, "rra\n", 4);
	return (0);
}
