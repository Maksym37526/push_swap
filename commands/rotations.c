/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaroshu <myaroshu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:25:27 by myaroshu          #+#    #+#             */
/*   Updated: 2025/12/23 11:04:03 by myaroshu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_stack_node **stack)
{
    t_stack_node    *last_node;

    if (!*stack || !(*stack)->next)
        return ; 
    last_node = find_last(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

void    ra(t_stack_node **a, bool print)
{
    rotate(a);
    if (print)
        write(1, "ra\n", 3);
}

void    rb(t_stack_node **b, bool print)
{
    rotate(b);
    if (print)
        write(1, "rb\n", 3);
}

void    rr(t_stack_node **a, t_stack_node **b, bool print)
{
    rotate(a);
    rotate(b);
    if (print)
        write(1, "rr\n", 3);
}