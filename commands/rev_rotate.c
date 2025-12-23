/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaroshu <myaroshu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:33:30 by myaroshu          #+#    #+#             */
/*   Updated: 2025/12/23 11:03:51 by myaroshu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
	{
		return ;
	}
	last = find_last(*stack);
	last->prev->next = *stack;
	last->next = NULL;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a, bool print)
{
	reverse_rotate(a);
	if (!print)
	{
		printf("rra\n");
	}
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate(b);
	if (!print)
	{
		printf("rrb\n");
	}
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
	{
		printf("rrr\n");
	}
}
