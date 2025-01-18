/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_bottom_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:14:03 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/17 22:30:47 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_update_bottom_five(t_stack *stack, t_node *smallest_nod, int i)
{
	if (!stack || !stack->bottom_five || !smallest_nod)
		return (1);
	if (i == 0)
		stack->bottom_five->one = smallest_nod;
	else if (i == 1)
		stack->bottom_five->two = smallest_nod;
	else if (i == 2)
		stack->bottom_five->three = smallest_nod;
	else if (i == 3)
		stack->bottom_five->four = smallest_nod;
	else if (i == 4)
		stack->bottom_five->five = smallest_nod;
	return (0);
}

static int	ft_find_bottom_five(t_stack *stack, t_node **smallest_nod)
{
	t_node	*tmp_nod;

	if (!stack || !stack->top)
		return (0);
	tmp_nod = stack->top;
	while (tmp_nod)
	{
		if ((!(*smallest_nod) || tmp_nod->num < (*smallest_nod)->num)
			&& tmp_nod != stack->bottom_five->one
			&& tmp_nod != stack->bottom_five->two
			&& tmp_nod != stack->bottom_five->three
			&& tmp_nod != stack->bottom_five->four
			&& tmp_nod != stack->bottom_five->five)
		{
			*smallest_nod = tmp_nod;
		}
		tmp_nod = tmp_nod->next;
	}
	return (*smallest_nod != NULL);
}

int	ft_get_bottom_5_nod(t_stack *stack)
{
	t_node	*smallest_nod;
	int		i;

	if (!stack || !stack->top || !stack->bottom_five)
		return (-1);
	i = 0;
	while (i < 5)
	{
		smallest_nod = NULL;
		if (!ft_find_bottom_five(stack, &smallest_nod))
			break ;
		ft_update_bottom_five(stack, smallest_nod, i);
		i++;
	}
	return (0);
}
