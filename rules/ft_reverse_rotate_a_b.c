/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_a_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:22:10 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/17 21:56:27 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("rrr\n");
	return (ft_rra(stack_a, 0) || ft_rrb(stack_b, 0));
}
