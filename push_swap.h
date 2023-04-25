/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:19:07 by arforouz          #+#    #+#             */
/*   Updated: 2023/04/17 20:07:05 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				pos;
	int				dest_pos;
	int				cost_a;
	int				cost_b;
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack		*fill_stack_values(int argc, char **argv);
void		assign_index(t_stack *stack_a, int ac);

int			is_sorted(t_stack *stack);
void		sub_sort(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);

int			find_min_position(t_stack **stack);
void		find_dest_position(t_stack **stack_a, t_stack **stack_b);

void		find_cost(t_stack **stack_a, t_stack **stack_b);
void		make_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void		make_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

void		m_rr(t_stack **stack_a, t_stack **stack_b);
void		m_ra(t_stack **stack_a);
void		m_rb(t_stack **stack_b);
void		m_rrr(t_stack **stack_a, t_stack **stack_b);
void		m_rra(t_stack **stack_a);
void		m_rrb(t_stack **stack_b);
void		m_sa(t_stack **stack_a);
void		m_sb(t_stack **stack_b);
void		m_ss(t_stack **stack_a, t_stack **stack_b);
void		push_a(t_stack **stack_a, t_stack **stack_b);
void		push_b(t_stack **stack_a, t_stack **stack_b);

int			stack_size(t_stack	*stack);
t_stack		*stack_last_element(t_stack *stack);
t_stack		*stack_penultimate_element(t_stack *stack);
t_stack		*stack_new_element(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);

void		free_stack(t_stack **stack);
void		free_str(char **lst);
long int	ft_atoi(const char *str, t_stack *stack_a);
int			abslt(int nb);

void		error_message(t_stack **stack_a, t_stack **stack_b);

int			check_up(t_stack *stack);
int			is_sign(char c);

size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);

#endif