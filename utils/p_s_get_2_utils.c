/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_get_2_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:07:04 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/17 22:31:51 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_get_smallest_nod(t_stack *stack)
{
	t_node	*tmp_nod;
	t_node	*smallest_nod;

	tmp_nod = stack->top;
	smallest_nod = tmp_nod;
	while (tmp_nod)
	{
		if (smallest_nod->num > tmp_nod->num)
			smallest_nod = tmp_nod;
		tmp_nod = tmp_nod->next;
	}
	return (smallest_nod);
}

t_node	*ft_get_biggest_nod(t_stack *stack)
{
	t_node	*tmp_nod;
	t_node	*biggest_nod;

	tmp_nod = stack->top;
	biggest_nod = tmp_nod;
	while (tmp_nod)
	{
		if (biggest_nod->num < tmp_nod->num)
			biggest_nod = tmp_nod;
		tmp_nod = tmp_nod->next;
	}
	return (biggest_nod);
}

t_node	*ft_get_middle_nod(t_stack *stack)
{
	t_node	*tmp_nod_1;
	t_node	*tmp_nod_2;
	t_node	*middle_node;
	int		smaller_count;

	tmp_nod_1 = stack->top;
	middle_node = tmp_nod_1;
	while (tmp_nod_1)
	{
		smaller_count = 0;
		tmp_nod_2 = stack->top;
		while (tmp_nod_2)
		{
			if (tmp_nod_1->num > tmp_nod_2->num)
				smaller_count++;
			tmp_nod_2 = tmp_nod_2->next;
		}
		if (smaller_count == stack->middle_pos - 1)
			return (middle_node = tmp_nod_1);
		tmp_nod_1 = tmp_nod_1->next;
	}
	return (middle_node);
}
