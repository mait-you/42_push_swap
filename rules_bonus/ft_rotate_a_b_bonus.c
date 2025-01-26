/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_a_b_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:11:37 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/25 10:17:32 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	return (ft_ra(stack_a, PRINT) || ft_rb(stack_b, PRINT));
}
