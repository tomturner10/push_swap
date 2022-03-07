/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:44:13 by tturner           #+#    #+#             */
/*   Updated: 2021/09/07 10:44:13 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	character;

	src = (unsigned char *) s;
	character = (unsigned char) c;
	while (n > 0)
	{
		if (*src == character)
			return (src);
		n--;
		src++;
	}
	return ((unsigned char *) '\0');
}
