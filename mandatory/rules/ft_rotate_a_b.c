/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:11:37 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/25 10:14:01 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "rr\n", 3);
	return (ft_ra(stack_a, !PRINT) || ft_rb(stack_b, !PRINT));
}
