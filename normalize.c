/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:47:54 by tturner           #+#    #+#             */
/*   Updated: 2022/03/02 13:47:54 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int	ft_size(t_linkedList *stack)
{
	int		size;
	t_link	*hold;

	size = 0;
	hold = stack->top;
	while (hold->next != NULL)
	{
		hold = hold->next;
		size++;
	}
	return (size + 1);
}

static int	*ft_fill_array(t_linkedList *stack)
{
	int		*rtn;
	t_link	*hold;
	int		i;

	i = 0;
	rtn = (int *)malloc(sizeof(int) * ft_size(stack));
	hold = stack->top;
	while (hold->next != NULL)
	{
		rtn[i] = hold->num;
		hold = hold->next;
		i++;
	}
	rtn[i] = hold->num;
	return (rtn);
}

static void	ft_bubble_sort(int *array, int array_size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
	while (i < (array_size - 1))
	{
		j = 0;
		while (j < array_size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_normalize(t_linkedList *stack)
{
	int		*array;
	int		i;
	t_link	*hold;

	array = ft_fill_array(stack);
	hold = stack->top;
	ft_bubble_sort(array, ft_size(stack));
	while (hold != NULL)
	{
		i = 0;
		while (i < ft_size(stack))
		{
			if (array[i] == hold->num)
			{
				hold->normalized = i + 1;
				break ;
			}
			i++;
		}
		hold = hold->next;
	}
}
