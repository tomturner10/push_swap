/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:47:55 by tturner           #+#    #+#             */
/*   Updated: 2022/03/02 13:47:55 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void	ft_put_top_inorder_five(t_stacks *stacks)
{
	int	top;

	top = stacks->stack_b->top->normalized;
	if (top > stacks->stack_a->top->next->next->normalized
		&& top < stacks->stack_a->top->next->next->next->normalized)
	{
		ft_choose_op(stacks, "rra");
		ft_choose_op(stacks, "pa");
		ft_choose_op(stacks, "ra");
		ft_choose_op(stacks, "ra");
	}
}

void	ft_put_top_inorder_four(t_stacks *stacks)
{
	int	top;

	top = stacks->stack_b->top->normalized;
	if (top > stacks->stack_a->top->normalized
		&& top < stacks->stack_a->top->next->normalized)
	{
		ft_choose_op(stacks, "ra");
		ft_choose_op(stacks, "pa");
		ft_choose_op(stacks, "rra");
	}
	else if (top > stacks->stack_a->top->next->normalized
		&& top < stacks->stack_a->top->next->next->normalized)
	{
		ft_choose_op(stacks, "ra");
		ft_choose_op(stacks, "ra");
		ft_choose_op(stacks, "pa");
		ft_choose_op(stacks, "rra");
		ft_choose_op(stacks, "rra");
	}
	else if (ft_size(stacks->stack_a) >= 3)
		ft_put_top_inorder_five(stacks);
}

void	ft_sort_three(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->stack_a->top->normalized;
	b = stacks->stack_a->top->next->normalized;
	c = stacks->stack_a->top->next->next->normalized;
	if (a > b && b < c && a < c)
		ft_choose_op(stacks, "sa");
	else if (a > b && b > c && a > c)
	{
		ft_choose_op(stacks, "sa");
		ft_choose_op(stacks, "rra");
	}
	else if (a > b && b < c && a > c)
		ft_choose_op(stacks, "ra");
	else if (a < c && b > c && a < b)
	{
		ft_choose_op(stacks, "sa");
		ft_choose_op(stacks, "ra");
	}
	else if (a < b && c < b && a > c)
		ft_choose_op(stacks, "rra");
}

void	ft_sort_five(t_stacks *stacks)
{
	if (stacks->stack_b->top->normalized < stacks->stack_a->top->normalized)
		ft_choose_op(stacks, "pa");
	else if (stacks->stack_b->top->normalized
		> ft_last(stacks->stack_a)->normalized)
	{
		ft_choose_op(stacks, "pa");
		ft_choose_op(stacks, "ra");
	}
	else
		ft_put_top_inorder_four(stacks);
}

void	ft_sort_small_stack(t_stacks *stacks)
{
	int	size;

	size = ft_size(stacks->stack_a);
	if (size == 2)
		ft_choose_op(stacks, "ra");
	else if (size == 3)
		ft_sort_three(stacks);
	else if (size >= 4)
	{
		ft_choose_op(stacks, "pb");
		if (size == 5)
			ft_choose_op(stacks, "pb");
		if (!ft_is_sorted(stacks->stack_a))
			ft_sort_three(stacks);
		ft_sort_five(stacks);
		if (size == 5)
			ft_sort_five(stacks);
	}
}
