/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:14:47 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/16 15:59:50 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_nod(t_stack *stack)
{
	t_node	*tmp_nod;
	t_node	*next;

	if (!stack)
		return ;
	tmp_nod = stack->top;
	while (tmp_nod)
	{
		next = tmp_nod->next;
		if (tmp_nod->best_move)
			free(tmp_nod->best_move);
		free(tmp_nod);
		tmp_nod = next;
	}
	free(stack->top_five);
	free(stack);
}

void	free_args(char **args)
{
	int	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

int	ft_is_stack_sorted(t_stack *stack_a)
{
	t_node	*tmp;

	tmp = stack_a->top;
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->num > tmp->next->num)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	sort_a(t_stack *stack_a)
{
	t_node	*tmp_nod;
	int		price;
	int		direction;

	tmp_nod = ft_get_smallest_nod(stack_a);
	price = tmp_nod->price;
	direction = tmp_nod->direction;
	if (direction == -1)
		while (price-- > 0)
			ft_rra(stack_a, PRINT);
	else if (direction == 1)
		while (price-- > 0)
			ft_ra(stack_a, PRINT);
	return (0);
}
