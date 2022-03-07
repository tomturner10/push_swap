/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:47:54 by tturner           #+#    #+#             */
/*   Updated: 2022/03/02 13:47:54 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

t_stacks	*ft_init_stacks(char **argv)
{
	t_stacks		*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->stack_a = ft_init_linked_list();
	stacks->stack_b = ft_init_linked_list();
	while (*argv)
	{
		if (!ft_is_valid(*argv)
			|| !ft_duplicate(stacks->stack_a, ft_atoi(*argv)))
		{
			write(1, "Error\n", 6);
			exit(-1);
		}
		ft_push_link(stacks->stack_a, ft_atoi(*argv++));
	}
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (-1);
	stacks = ft_init_stacks(&argv[1]);
	if (ft_is_sorted(stacks->stack_a))
		return (0);
	ft_normalize(stacks->stack_a);
	if (ft_size(stacks->stack_a) <= 5)
		ft_sort_small_stack(stacks);
	else
		ft_sort_large_stack(stacks);
	ft_free_links(stacks->stack_a);
	ft_free_links(stacks->stack_b);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
	return (0);
}
