/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ten.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:30:06 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/25 11:58:34 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_ten(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 5)
	{
		ft_memset(stack_a->top_five, 0, sizeof(t_top_five));
		ft_get_top_5_nod(stack_a);
		if (ft_is_top_5(stack_a, stack_a->top))
			ft_pb(stack_a, stack_b, PRINT);
		else
			ft_ra(stack_a, PRINT);
	}
	sort_five_or_less(stack_a, stack_b);
	r_sort_five_or_less(stack_b, stack_a);
	while (stack_b->size > 0)
		ft_pa(stack_b, stack_a, PRINT);
	return (0);
}
