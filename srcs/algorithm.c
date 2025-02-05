/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:48:13 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/04 10:09:49 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_smart_move(t_stack *stack_b, t_best_moves **bm)
{
	t_node			*tmp_nod;

	tmp_nod = stack_b->top;
	*bm = tmp_nod->best_move;
	while (tmp_nod)
	{
		if ((*bm)->total_cost == 0 || (*bm)->total_cost == 1)
			return (0);
		if (tmp_nod->best_move->total_cost < (*bm)->total_cost)
			*bm = tmp_nod->best_move;
		tmp_nod = tmp_nod->next;
	}
	return (0);
}

int	ft_aplyy_moves(t_stack *stack_b, t_stack *stack_a, t_best_moves *bm)
{
	while (bm->rr_count-- > 0)
		ft_rr(stack_a, stack_b);
	while (bm->rrr_count-- > 0)
		ft_rrr(stack_a, stack_b);
	while (bm->rb_count-- > 0)
		ft_rb(stack_b, PRINT);
	while (bm->rrb_count-- > 0)
		ft_rrb(stack_b, PRINT);
	while (bm->ra_count-- > 0)
		ft_ra(stack_a, PRINT);
	while (bm->rra_count-- > 0)
		ft_rra(stack_a, PRINT);
	ft_pa(stack_b, stack_a, PRINT);
	return (0);
}

int	ft_push_middle(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*middle_nod;
	int		i;
	int		spacing;

	spacing = 0;
	while (1)
	{
		middle_nod = ft_get_middle_nod(stack_a, spacing);
		if (middle_nod->price <= stack_a->middle_pos / 2 \
			&& !ft_is_top_5(stack_a, middle_nod))
			break ;
		spacing++;
	}
	i = middle_nod->price;
	if (middle_nod->direction == -1)
		while (i-- > 0)
			ft_rra(stack_a, PRINT);
	else if (middle_nod->direction == 1)
		while (i-- > 0)
			ft_ra(stack_a, PRINT);
	return (ft_pb(stack_a, stack_b, PRINT));
}

int	push_quick_sort_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*pivot;

	ft_get_top_5_nod(stack_a);
	ft_push_middle(stack_a, stack_b);
	pivot = stack_b->top;
	while (stack_a->size > 5)
	{
		if (!ft_is_top_5(stack_a, stack_a->top))
		{
			ft_pb(stack_a, stack_b, PRINT);
			if (pivot->num < stack_b->top->num)
				ft_rb(stack_b, PRINT);
		}
		else
			ft_ra(stack_a, PRINT);
	}
	if (stack_a->size == 5)
		sort_five_or_less(stack_a, stack_b);
	return (0);
}

int	push_back_sort_a(t_stack *stack_b, t_stack *stack_a)
{
	t_best_moves	*bm;

	while (stack_b->size > 0)
	{
		bm = NULL;
		ft_update_target(stack_a, stack_b);
		ft_smart_move(stack_b, &bm);
		ft_aplyy_moves(stack_b, stack_a, bm);
	}
	if (!ft_is_stack_sorted(stack_a))
		sort_a(stack_a);
	return (0);
}
