/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:36:43 by tturner           #+#    #+#             */
/*   Updated: 2021/09/15 14:36:43 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		rtn;
	t_list	*temp;

	rtn = 1;
	if (lst == NULL)
		return (0);
	temp = lst;
	while (temp->next != NULL)
	{
		rtn++;
		temp = temp->next;
	}
	return (rtn);
}
