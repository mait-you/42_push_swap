/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_top_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:13:39 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/02 15:23:07 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_update_top_five(t_stack *stack, t_node *biggest_nod, int i)
{
	if (i == 0)
		stack->top_five->one = biggest_nod;
	else if (i == 1)
		stack->top_five->two = biggest_nod;
	else if (i == 2)
		stack->top_five->three = biggest_nod;
	else if (i == 3)
		stack->top_five->four = biggest_nod;
	else if (i == 4)
		stack->top_five->five = biggest_nod;
	return (0);
}

static int	ft_find_top_five(t_stack *stack, t_node **biggest_nod)
{
	t_node	*tmp_nod;

	tmp_nod = stack->top;
	while (tmp_nod)
	{
		if ((!(*biggest_nod) || tmp_nod->num > (*biggest_nod)->num)
			&& tmp_nod != stack->top_five->one
			&& tmp_nod != stack->top_five->two
			&& tmp_nod != stack->top_five->three
			&& tmp_nod != stack->top_five->four
			&& tmp_nod != stack->top_five->five)
		{
			*biggest_nod = tmp_nod;
		}
		tmp_nod = tmp_nod->next;
	}
	return (*biggest_nod != NULL);
}

int	ft_get_top_5_nod(t_stack *stack)
{
	t_node	*biggest_nod;
	int		i;

	if (!stack || !stack->top || !stack->top_five)
		return (-1);
	ft_memset(stack->top_five, 0, sizeof(t_top_five));
	i = 0;
	while (i < 5)
	{
		biggest_nod = NULL;
		if (!ft_find_top_five(stack, &biggest_nod))
			break ;
		ft_update_top_five(stack, biggest_nod, i);
		i++;
	}
	return (0);
}
