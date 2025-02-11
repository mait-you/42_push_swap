/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a_b_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:17:07 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/25 10:17:26 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	return (ft_sa(stack_a, PRINT) || ft_sb(stack_b, PRINT));
}
