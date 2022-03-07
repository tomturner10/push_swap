/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:44:14 by tturner           #+#    #+#             */
/*   Updated: 2021/09/07 10:44:14 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*o;

	o = NULL;
	i = 0;
	while (s[i] != '\0' )
	{
		if (s[i] == c)
			o = (char *)&s[i];
		i++;
	}
	if (s[i] == c)
		o = (char *)&s[i];
	return (o);
}
