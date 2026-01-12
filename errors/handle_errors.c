/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaroshu <myaroshu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 13:45:41 by myaroshu          #+#    #+#             */
/*   Updated: 2026/01/11 16:44:01 by myaroshu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (!((str[i] == '+' || str[i] == '-') || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if (str[i] == '+' || str[i] == '-')
	{
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (1);
	}
	i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
/*якщо наступний символ після "+/-" не >= '0' aбо <= '9', ПОМИЛКА* (line 25)*/

int	error_duplicate(t_stack_node *a, long n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->next = NULL;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

int	free_errors(t_stack_node **a_stack)
{
	free_stack(a_stack);
	write(2, "Error\n", 6);
	exit(1);
}
