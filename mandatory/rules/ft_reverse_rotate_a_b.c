/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_a_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:22:10 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/25 10:13:56 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "rrr\n", 4);
	return (ft_rra(stack_a, !PRINT) || ft_rrb(stack_b, !PRINT));
}
