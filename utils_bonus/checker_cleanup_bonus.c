/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_cleanup_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 08:49:20 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/26 09:28:14 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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
		free(tmp_nod);
		tmp_nod = next;
	}
	free(stack);
}

void	free_instructions(t_instruct *instructions)
{
	t_instruct	*tmp_instruct;
	t_instruct	*next_instruct;

	if (!instructions)
		return ;
	tmp_instruct = instructions;
	while (tmp_instruct)
	{
		next_instruct = tmp_instruct->next;
		free(tmp_instruct);
		tmp_instruct = next_instruct;
	}
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	error_cleanup(t_stack *stack_a, t_stack *stack_b, \
	t_instruct *instructions)
{
	if (stack_a)
		free_nod(stack_a);
	if (stack_b)
		free_nod(stack_b);
	if (instructions)
		free_instructions(instructions);
	write(2, "Error\n", 6);
	exit(1);
}
