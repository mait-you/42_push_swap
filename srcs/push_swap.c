/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:43:27 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/06 09:59:06 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// main sorting function
int	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b || stack_a->size <= 1)
		return (1);
	if (stack_a->size <= 5)
		return (sort_five_or_less(stack_a, stack_b));
	if (stack_a->size <= 10)
		return (sort_ten(stack_a, stack_b));
	if (stack_a->size > 10)
	{
		push_quick_sort_b(stack_a, stack_b);
		push_back_sort_a(stack_b, stack_a);
	}
	return (0);
}

static int	ft_chek_args_rpt(t_stack *stack_a)
{
	t_node	*tmp_0;
	t_node	*tmp_1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp_0 = stack_a->top;
	while (tmp_0 && i < stack_a->size)
	{
		j = 0;
		tmp_1 = stack_a->top;
		while (tmp_1 && j < i)
		{
			if (tmp_0->num == tmp_1->num)
				return (1);
			tmp_1 = tmp_1->next;
			j++;
		}
		tmp_0 = tmp_0->next;
		i++;
	}
	return (0);
}

static int	ft_get_and_chek_args(int ac, char **av, t_stack *stack_a)
{
	char	**tmp_args;
	int		error;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		tmp_args = ft_split(av[i], ' ');
		if (!tmp_args || tmp_args[0] == 0)
			return (free_args(tmp_args), 1);
		j = 0;
		while (tmp_args[j])
		{
			error = 1;
			ft_add_nod_to_stk(stack_a, ft_new_nod(\
								ft_atoi(tmp_args[j], &error)));
			if (error)
				return (free_args(tmp_args), 1);
			j++;
		}
		free_args(tmp_args);
		i++;
	}
	return (ft_chek_args_rpt(stack_a) || ft_get_stk_info(stack_a));
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (1);
	stack_a = ft_new_stk();
	stack_b = ft_new_stk();
	if (ft_get_and_chek_args(ac, av, stack_a) || stack_a->size <= 0)
		return (free_nod(stack_a), free_nod(stack_b),
			write(2, "Error\n", 6), 1);
	if (!ft_is_stack_sorted(stack_a))
		sort_stack(stack_a, stack_b);
	free_nod(stack_a);
	free_nod(stack_b);
	return (0);
}
