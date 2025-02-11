/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_b_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:54:34 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/25 10:01:37 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	ft_rb(t_stack *stack_b, int print)
{
	t_node	*tmp_nod;

	if (stack_b->size < 2)
		return (1);
	tmp_nod = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->top->prev = NULL;
	stack_b->bottom->next = tmp_nod;
	tmp_nod->prev = stack_b->bottom;
	tmp_nod->next = NULL;
	stack_b->bottom = tmp_nod;
	if (print)
		write(1, "rb\n", 3);
	return (0);
}
