/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:44:07 by arforouz          #+#    #+#             */
/*   Updated: 2023/04/17 20:31:43 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_keep_three(t_stack **stack_a, t_stack **stack_b)
{
	int	pb;
	int	i;
	int	size;

	size = stack_size(*stack_a);
	pb = 0;
	i = 0;
	while (size > 6 && i < size && pb < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			push_b(stack_a, stack_b);
			pb++;
		}
		else
			m_ra(stack_a);
		i++;
	}
	while ((size - pb) > 3)
	{
		push_b(stack_a, stack_b);
		pb++;
	}
}

static void	switch_stack(t_stack **stack_a)
{
	int	least_pos;
	int	size;

	size = stack_size(*stack_a);
	least_pos = find_min_position(stack_a);
	if (least_pos > size / 2)
	{
		while (least_pos < size)
		{
			m_rra(stack_a);
			least_pos++;
		}
	}
	else
	{
		while (least_pos > 0)
		{
			m_ra(stack_a);
			least_pos--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	pb_keep_three(stack_a, stack_b);
	sub_sort(stack_a);
	while (*stack_b)
	{
		find_dest_position(stack_a, stack_b);
		find_cost(stack_a, stack_b);
		make_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		switch_stack(stack_a);
}
