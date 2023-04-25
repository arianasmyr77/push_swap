/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:32:18 by arforouz          #+#    #+#             */
/*   Updated: 2023/04/17 19:06:44 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abslt(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	find_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		len_a;
	int		len_b;
	t_stack	*a;
	t_stack	*b;

	a = *stack_a;
	b = *stack_b;
	len_a = stack_size(a);
	len_b = stack_size(b);
	while (b)
	{
		b->cost_b = b->pos;
		if (b->pos > len_b / 2)
			b->cost_b = (len_b - b->pos) * -1;
		b->cost_a = b->dest_pos;
		if (b->dest_pos > len_a / 2)
			b->cost_a = (len_a - b->dest_pos) * -1;
		b = b->next;
	}
}

void	make_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		price_a;
	int		price_b;

	cheapest = INT_MAX;
	tmp = *stack_b;
	while (tmp)
	{
		if (abslt(tmp->cost_a) + abslt(tmp->cost_b) < abslt(cheapest))
		{
			cheapest = abslt(tmp->cost_b) + abslt(tmp->cost_a);
			price_a = tmp->cost_a;
			price_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	make_move(stack_a, stack_b, price_a, price_b);
}
