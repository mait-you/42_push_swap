/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:26:44 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/25 10:01:35 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	ft_ra(t_stack *stack_a, int print)
{
	t_node	*tmp_nod;

	if (stack_a->size < 2)
		return (1);
	tmp_nod = stack_a->top;
	stack_a->top = stack_a->top->next;
	stack_a->top->prev = NULL;
	stack_a->bottom->next = tmp_nod;
	tmp_nod->prev = stack_a->bottom;
	tmp_nod->next = NULL;
	stack_a->bottom = tmp_nod;
	if (print)
		write(1, "ra\n", 3);
	return (0);
}
