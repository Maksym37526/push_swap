/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myaroshu <myaroshu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:58:59 by myaroshu          #+#    #+#             */
/*   Updated: 2026/01/12 13:29:57 by myaroshu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_sort(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) == 2)
		sa(a, true);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**split_args;

	a = NULL;
	b = NULL;
	split_args = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		split_args = ft_split(argv[1], ' ');
	if (argc == 2)
		init_stack_a(&a, split_args);
	else
		init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
		choose_sort(&a, &b);
	free_stack(&a);
	if (argc == 2)
		free_matrix(split_args);
	return (0);
}
