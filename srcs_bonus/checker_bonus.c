/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:03:22 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/25 12:07:42 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	get_instructions(t_instruct **instructions)
{
	t_instruct	*new_instruct;
	char		*tmp;

	tmp = get_next_line(0);
	while (tmp)
	{
		new_instruct = ft_new_instruct(tmp);
		add_new_instruct(instructions, new_instruct);
		if (ft_check_instruct(new_instruct))
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		tmp = get_next_line(0);
	}
	return (1);
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
	return (ft_chek_args_rpt(stack_a));
}

static int	initialize_stacks(int ac, char **av, t_stack **stack_a, \
	t_stack **stack_b)
{
	*stack_a = ft_new_stk();
	*stack_b = ft_new_stk();
	if (ft_get_and_chek_args(ac, av, *stack_a) || (*stack_a)->size <= 0)
		return (1);
	if (ft_is_stack_sorted(*stack_a))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_instruct	*instructions;

	if (ac < 2)
		return (1);
	if (initialize_stacks(ac, av, &stack_a, &stack_b))
		error_cleanup(stack_a, stack_b, NULL);
	instructions = NULL;
	if (get_instructions(&instructions) == -1)
		error_cleanup(stack_a, stack_b, instructions);
	while (instructions)
	{
		aplyy_instructions(instructions->instruct, stack_a, stack_b);
		instructions = instructions->next;
	}
	if (ft_is_stack_sorted(stack_a) && stack_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_nod(stack_a);
	free_nod(stack_b);
	free_instructions(instructions);
	return (0);
}
