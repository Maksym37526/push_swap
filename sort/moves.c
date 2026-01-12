/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaroshu <myaroshu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 11:40:50 by myaroshu          #+#    #+#             */
/*   Updated: 2026/01/12 16:13:46 by myaroshu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (!cheapest_node || !cheapest_node->target_node)
		return ;
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(a, b, true);
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	if (!b || !*b || !(*b)->target_node)
		return ;
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, true);
}

void	min_on_top(t_stack_node **a)
{
	t_stack_node	*min_node;

	min_node = find_min(*a);
	while ((*a)->value != min_node->value)
	{
		current_index(*a);
		if (min_node->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}
