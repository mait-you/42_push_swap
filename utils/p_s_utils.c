/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:14:47 by mait-you          #+#    #+#             */
/*   Updated: 2025/01/18 11:09:29 by mait-you         ###   ########.fr       */
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
		free(tmp_nod);
		tmp_nod = next;
	}
	free(stack->top_five);
	free(stack->bottom_five);
	free(stack);
}

void	free_args(char **args)
{
	int	i;

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

int	ft_update_target(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp_nod;

	tmp_nod = stack_b->top;
	while (tmp_nod)
	{
		if (ft_is_bottom_5(stack_b, tmp_nod))
		{
			ft_get_f_target(tmp_nod, stack_b, stack_a);
			ft_get_a_target(tmp_nod, stack_a);
			tmp_nod->best_move = tmp_nod->a_target_nod->num - \
			tmp_nod->f_target_nod->num;
		}
		tmp_nod = tmp_nod->next;
	}
	return (0);
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

void print_stack(const char *stack_name, t_stack *stack)
{
	t_node *tmp_nod = stack->top;
	ft_printf("\n%s\n", stack_name);
	if (tmp_nod)
		ft_printf("stack->top :\033[33m%d\033[0m stack->bottom :\033[33m%d\033[0m stack->middle :\033[33m%d\033[0m stack->size : \033[33m%d\033[0m\n", stack->top->num, stack->bottom->num, stack->middle_pos, stack->size);
	while (tmp_nod)
	{
		ft_printf("position :\033[33m%d\033[0m ->num :\033[36m[%d]\033[0m direction :\033[33m%d\033[0m price :\033[33m%d\033[0m\n", \
		tmp_nod->position, tmp_nod->num, tmp_nod->direction, tmp_nod->price);
		tmp_nod = tmp_nod->next;
	}
}

void print_sort_stack(const char *stack_name, t_stack *stack)
{
	t_node	*tmp_nod = stack->top;
	ft_printf("\nsort_%s: ", stack_name);
	while (tmp_nod)
	{
		ft_printf("%d ", tmp_nod->num);
		tmp_nod = tmp_nod->next;
	}
	ft_printf("\nstack->size : %d\n", stack->size);
	ft_printf("stack->middle : %d\n", stack->middle_pos);
}

void print_stack__(const char *stack_name, t_stack *stack)
{
	t_node *tmp_nod = stack->top;
	ft_printf("\n%s\n", stack_name);
	if (tmp_nod)
		ft_printf("stack->top :\033[33m%d\033[0m stack->bottom :\033[33m%d\033[0m stack->middle :\033[33m%d\033[0m stack->size : \033[33m%d\033[0m\n", stack->top->num, stack->bottom->num, stack->middle_pos, stack->size);
	while (tmp_nod)
	{
		ft_printf("position :\033[33m%d\033[0m ->num :\033[36m[%d]\033[0m direction :\033[33m%d\033[0m price :\033[33m%d\033[0m ", \
		tmp_nod->position, tmp_nod->num, tmp_nod->direction, tmp_nod->price);
		if (ft_is_bottom_5(stack, tmp_nod))
			ft_printf("f_target :\033[33m%d\033[0m a_target :\033[33m%d\033[0m best_move :\033[33m%d\033[0m\n", tmp_nod->f_target_nod->num, tmp_nod->a_target_nod->num, tmp_nod->best_move);
		else
			ft_printf("target :%s\n", tmp_nod->f_target_nod);
		tmp_nod = tmp_nod->next;
	}
}