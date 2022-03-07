/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:36:42 by tturner           #+#    #+#             */
/*   Updated: 2021/09/15 14:36:42 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*rtn;

	if (lst == NULL)
		return (NULL);
	rtn = lst;
	while (rtn->next != NULL)
		rtn = rtn->next;
	return (rtn);
}
