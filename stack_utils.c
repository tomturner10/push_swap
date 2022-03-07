/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:47:55 by tturner           #+#    #+#             */
/*   Updated: 2022/03/02 13:47:55 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

t_linkedList	*ft_init_linked_list(void)
{
	t_linkedList	*rtn;

	rtn = (t_linkedList *) malloc(sizeof(t_linkedList *));
	rtn->top = NULL;
	return (rtn);
}

void	ft_push_link(t_linkedList *stack, int value)
{
	t_link	*link;

	link = (t_link *)malloc(sizeof(t_link *));
	link->next = NULL;
	link->normalized = 0;
	link->num = value;
	if (stack->top == NULL)
		stack->top = link;
	else
		ft_last(stack)->next = link;
}

t_link	*ft_last(t_linkedList *stack)
{
	t_link	*hold;

	hold = stack->top;
	while (hold != NULL && hold->next != NULL)
		hold = hold->next;
	return (hold);
}

t_link	*ft_get_index(t_linkedList *stack, int index)
{
	int		i;
	t_link	*hold;

	i = 0;
	hold = stack->top;
	while (hold->next != NULL && i < index)
	{
		hold = hold->next;
		i++;
	}
	if (i != index - 1)
		return (NULL);
	return (hold);
}

int	ft_duplicate(t_linkedList *stack, int num)
{
	t_link	*hold;

	hold = stack->top;
	while (hold != NULL)
	{
		if (hold->num == num)
			return (0);
		hold = hold->next;
	}
	return (1);
}
