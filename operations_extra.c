/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:47:54 by tturner           #+#    #+#             */
/*   Updated: 2022/03/02 13:47:54 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

void	ft_rotate(t_linkedList *stack)
{
	t_link	*hold;

	hold = stack->top;
	ft_last(stack)->next = stack->top;
	stack->top = stack->top->next;
	hold->next = NULL;
}

void	ft_reverse_rotate(t_linkedList *stack)
{
	t_link	*hold;
	t_link	*last;

	last = ft_last(stack);
	hold = stack->top;
	while (hold->next != last)
		hold = hold->next;
	last->next = stack->top;
	stack->top = last;
	hold->next = NULL;
}

int	ft_is_sorted(t_linkedList *stack)
{
	t_link	*hold;

	hold = stack->top;
	if (hold == NULL || hold->next == NULL)
		return (1);
	while (hold != NULL && hold->next != NULL && hold->next->num > hold->num)
	{
		if (hold->next->next == NULL)
		{
			return (1);
		}
		hold = hold->next;
	}
	return (0);
}
