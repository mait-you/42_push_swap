/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_get_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:02:34 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/17 22:33:19 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_get_stk_info(t_stack *stack)
{
	t_node	*tmp_nod;
	int		pos;

	if (stack->size % 2 == 0)
		stack->middle_pos = (stack->size / 2);
	else if (stack->size % 2 != 0)
		stack->middle_pos = (stack->size / 2) + 1;
	pos = 1;
	tmp_nod = stack->top;
	while (tmp_nod)
	{
		tmp_nod->position = pos++;
		if (tmp_nod->position > stack->middle_pos)
		{
			tmp_nod->direction = -1;
			tmp_nod->price = (stack->size - tmp_nod->position) + 1;
		}
		else if (tmp_nod->position <= stack->middle_pos)
		{
			tmp_nod->direction = 1;
			tmp_nod->price = tmp_nod->position - 1;
		}
		tmp_nod = tmp_nod->next;
	}
	return (0);
}

int	ft_get_a_target(t_node *tmp_nod, t_stack *stack_a)
{
	t_node	*tmp_nod_1;
	int		top_b;

	top_b = tmp_nod->num + 1;
	while (top_b <= stack_a->top_five->one->num)
	{
		tmp_nod_1 = stack_a->top;
		while (tmp_nod_1)
		{
			if (top_b == tmp_nod_1->num)
				return ((tmp_nod->a_target_nod = tmp_nod_1), 0);
			tmp_nod_1 = tmp_nod_1->next;
		}
		top_b++;
	}
	return (1);
}

int	ft_get_f_target(t_node *tmp_nod, t_stack *stack_b, t_stack *stack_a)
{
	t_node	*tmp_nod_1;
	int		top_b;

	top_b = tmp_nod->num + 1;
	while (top_b <= stack_a->top_five->one->num)
	{
		tmp_nod_1 = stack_a->top;
		while (tmp_nod_1)
		{
			if (top_b == tmp_nod_1->num)
				return ((tmp_nod->f_target_nod = tmp_nod_1), 0);
			tmp_nod_1 = tmp_nod_1->next;
		}
		tmp_nod_1 = stack_b->top;
		while (tmp_nod_1)
		{
			if (top_b == tmp_nod_1->num)
				return ((tmp_nod->f_target_nod = tmp_nod_1), 0);
			tmp_nod_1 = tmp_nod_1->next;
		}
		top_b++;
	}
	return (1);
}

int	ft_is_top_5(t_stack *stack, t_node *nod)
{
	if (!stack || !stack->top || !stack->top_five)
		return (1);
	if (nod == stack->top_five->one || nod == stack->top_five->two
		|| nod == stack->top_five->three || nod == stack->top_five->four
		|| nod == stack->top_five->five)
		return (0);
	return (1);
}

int	ft_is_bottom_5(t_stack *stack, t_node *nod)
{
	if (!stack || !stack->top || !stack->bottom_five)
		return (1);
	if (nod == stack->bottom_five->one || nod == stack->bottom_five->two
		|| nod == stack->bottom_five->three || nod == stack->bottom_five->four
		|| nod == stack->bottom_five->five)
		return (0);
	return (1);
}
