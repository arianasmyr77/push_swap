/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:01:29 by arforouz          #+#    #+#             */
/*   Updated: 2023/04/17 20:35:42 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_len)
{
	if (stack_len == 2 && !is_sorted(*stack_a))
		m_sa(stack_a);
	else if (stack_len == 3)
		sub_sort(stack_a);
	else if (stack_len > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

// void ft_leaks()
// {
// 	system("leaks push_swap");
// 		atexit(ft_leaks);
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = fill_stack_values(argc, argv);
	if (!stack_a || check_up(stack_a))
		error_message(&stack_a, NULL);
	len = stack_size(stack_a);
	assign_index(stack_a, len + 1);
	push_swap(&stack_a, &stack_b, len);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
