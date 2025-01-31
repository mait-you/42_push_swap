/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_new_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:47:47 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/30 17:18:16 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

t_node	*ft_new_nod(int data)
{
	t_node		*new_nod;

	new_nod = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new_nod)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	new_nod->num = data;
	return (new_nod);
}

t_stack	*ft_new_stk(void)
{
	t_stack			*new_stk;

	new_stk = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!new_stk)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (new_stk);
}

t_instruct	*ft_new_instruct(char *instruct)
{
	t_instruct			*new_instruct;

	new_instruct = (t_instruct *)ft_calloc(1, sizeof(t_instruct));
	if (!new_instruct)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	instruct[ft_strcspn(instruct, "\n")] = 0;
	new_instruct->instruct = ft_strdup(instruct);
	return (new_instruct);
}

int	add_new_instruct(t_instruct **instructions, t_instruct *new_instruct)
{
	t_instruct	*current;

	if (!new_instruct || !new_instruct)
		return (1);
	if (!*instructions)
	{
		*instructions = new_instruct;
		return (0);
	}
	current = *instructions;
	while (current->next)
		current = current->next;
	current->next = new_instruct;
	return (0);
}
