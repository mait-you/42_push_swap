/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:33:18 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/21 10:31:45 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	bm_total(t_best_moves *bm)
{
	bm->total_cost = bm->ra_count + bm->rb_count \
		+ bm->rr_count + bm->rra_count + bm->rrb_count + bm->rrr_count;
	return (0);
}

int	double_r(t_best_moves *bm)
{
	while (bm->ra_count > 0 && bm->rb_count > 0)
	{
		bm->ra_count--;
		bm->rb_count--;
		bm->rr_count++;
	}
	while (bm->rra_count > 0 && bm->rrb_count > 0)
	{
		bm->rra_count--;
		bm->rrb_count--;
		bm->rrr_count++;
	}
	return (0);
}

int	ft_update_target(t_stack *stack_a, t_stack *stack_b)
{
	t_node			*tmp_nod;
	t_best_moves	*tmp_bm;

	tmp_nod = stack_b->top;
	while (tmp_nod)
	{
		ft_get_a_target(tmp_nod, stack_a);
		tmp_bm = ft_new_best_moves(stack_a, stack_b);
		if (tmp_nod->direction == 1)
			tmp_bm->rb_count = tmp_nod->price;
		else
			tmp_bm->rrb_count = tmp_nod->price;
		if (tmp_nod->a_target_nod->direction == 1)
			tmp_bm->ra_count = tmp_nod->a_target_nod->price;
		else
			tmp_bm->rra_count = tmp_nod->a_target_nod->price;
		double_r(tmp_bm);
		bm_total(tmp_bm);
		if (tmp_nod && tmp_nod->best_move)
			free(tmp_nod->best_move);
		tmp_nod->best_move = tmp_bm;
		tmp_bm = NULL;
		tmp_nod = tmp_nod->next;
	}
	return (0);
}
