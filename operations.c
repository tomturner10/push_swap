/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:47:54 by tturner           #+#    #+#             */
/*   Updated: 2022/03/02 13:47:54 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

static void	ft_choose_op_rotation(t_stacks *stacks, char *operation)
{
	if (!ft_strncmp(operation, "rr", 3) || !ft_strncmp(operation, "ra", 3)
		|| !ft_strncmp(operation, "rb", 3))
	{
		if (!ft_strncmp(operation, "ra", 3) || !ft_strncmp(operation, "rr", 3))
			ft_rotate(stacks->stack_a);
		if (!ft_strncmp(operation, "rb", 3) || !ft_strncmp(operation, "rr", 3))
			ft_rotate(stacks->stack_b);
	}
	else if (!ft_strncmp(operation, "rrr", 3)
		|| !ft_strncmp(operation, "rra", 3) || !ft_strncmp(operation, "rrb", 3))
	{
		if (!ft_strncmp(operation, "rra", 3)
			|| !ft_strncmp(operation, "rrr", 3))
			ft_reverse_rotate(stacks->stack_a);
		if (!ft_strncmp(operation, "rrb", 3)
			|| !ft_strncmp(operation, "rrr", 3))
			ft_reverse_rotate(stacks->stack_b);
	}
}

void	ft_choose_op(t_stacks *stacks, char *operation)
{
	ft_putendl_fd(operation, 1);
	if (!ft_strncmp(operation, "ss", 3) || !ft_strncmp(operation, "sa", 3)
		|| !ft_strncmp(operation, "sb", 3))
	{
		if (!ft_strncmp(operation, "sa", 3) || !ft_strncmp(operation, "ss", 3))
			ft_swap(stacks->stack_a);
		if (!ft_strncmp(operation, "sb", 3) || !ft_strncmp(operation, "ss", 3))
			ft_swap(stacks->stack_b);
	}
	else if (!ft_strncmp(operation, "pa", 3))
		ft_push(stacks->stack_b, stacks->stack_a);
	else if (!ft_strncmp(operation, "pb", 3))
		ft_push(stacks->stack_a, stacks->stack_b);
	else
		ft_choose_op_rotation(stacks, operation);
}

void	ft_swap(t_linkedList *stack)
{
	int	num;
	int	normalized;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		num = stack->top->num;
		normalized = stack->top->normalized;
		stack->top->num = stack->top->next->num;
		stack->top->normalized = stack->top->next->normalized;
		stack->top->next->num = num;
		stack->top->next->normalized = normalized;
	}
}

void	ft_push(t_linkedList *origin, t_linkedList *dest)
{
	t_link	*hold;

	if (origin->top != NULL)
	{
		hold = origin->top->next;
		origin->top->next = dest->top;
		dest->top = origin->top;
		origin->top = hold;
	}
}
