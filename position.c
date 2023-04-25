/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:01:35 by arforouz          #+#    #+#             */
/*   Updated: 2023/04/17 20:30:25 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	find_min_position(t_stack **stack)
{
	t_stack	*temp;
	int		min_index;
	int		min_pos;

	temp = *stack;
	min_index = INT_MAX;
	assign_position(stack);
	min_pos = temp->pos;
	while (temp)
	{
		if (temp->index < min_index)
		{
			min_index = temp->index;
			min_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (min_pos);
}

static int	dest_position(t_stack **stack_a, int index_b,
											int dest_idx, int dest_pos)
{
	t_stack	*a;

	a = *stack_a;
	while (a)
	{
		if (a->index > index_b && a->index < dest_idx)
		{
			dest_idx = a->index;
			dest_pos = a->pos;
		}
		a = a->next;
	}
	if (dest_idx != INT_MAX)
		return (dest_pos);
	a = *stack_a;
	while (a)
	{
		if (a->index < dest_idx)
		{
			dest_idx = a->index;
			dest_pos = a->pos;
		}
		a = a->next;
	}
	return (dest_pos);
}

void	find_dest_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		dest_pos;

	b = *stack_b;
	assign_position(stack_a);
	assign_position(stack_b);
	dest_pos = 0;
	while (b)
	{
		dest_pos = dest_position(stack_a, b->index, INT_MAX, dest_pos);
		b->dest_pos = dest_pos;
		b = b->next;
	}
}
