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

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
	{
		return ;
	}
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void    rra(t_stack_node **a, bool print)
{
    reverse_rotate(a);
    if (print)
        write(1, "rra\n", 4);
}

void    rrb(t_stack_node **b, bool print)
{
    reverse_rotate(b);
    if (print)
        write(1, "rrb\n", 4);
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    reverse_rotate(a);
    reverse_rotate(b);
    if (print)
        write(1, "rrr\n", 4);
}
