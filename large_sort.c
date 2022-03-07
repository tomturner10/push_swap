/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:47:54 by tturner           #+#    #+#             */
/*   Updated: 2022/03/02 13:47:54 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int	ft_countbits(int size)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (i < sizeof(i) * 8)
	{
		if (size >> i & 1)
			count = i;
		i++;
	}
	return (count + 1);
}

void	ft_sort_large_stack(t_stacks *stacks)
{
	int	size;
	int	bits;
	int	num;
	int	i;
	int	j;

	size = ft_size(stacks->stack_a);
	bits = ft_countbits(size);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			num = stacks->stack_a->top->normalized;
			if ((num >> i) & 1)
				ft_choose_op(stacks, "ra");
			else
				ft_choose_op(stacks, "pb");
			j++;
		}
		while (stacks->stack_b->top != NULL)
			ft_choose_op(stacks, "pa");
		i++;
	}
}
