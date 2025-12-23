/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaroshu <myaroshu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 10:50:45 by myaroshu          #+#    #+#             */
/*   Updated: 2025/12/23 13:16:57 by myaroshu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*pushh;

	if (!src)
		return ;
	pushh = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	pushh->prev = NULL;
	if (!dest)
	{
		*dest = pushh;
		pushh->next = NULL;
	}
	else
	{
		pushh->next = *dest;
		pushh->next->prev = pushh;
		*dest = pushh;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		printf("pa\n");
}

void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (!print)
		printf("pb\n");
}
