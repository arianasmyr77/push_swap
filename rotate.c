/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:25:27 by arforouz          #+#    #+#             */
/*   Updated: 2023/04/17 20:29:05 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*end;
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	end = stack_last_element(*stack);
	tmp->next = NULL;
	end->next = tmp;
}

void	m_ra(t_stack **stack_a)
{
	rotate(stack_a);
	write (1, "ra\n", 3);
}

void	m_rb(t_stack **stack_b)
{
	rotate(stack_b);
	write (1, "rb\n", 3);
}

void	m_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write (1, "rr\n", 3);
}
