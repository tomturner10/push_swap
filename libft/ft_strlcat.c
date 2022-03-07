/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:44:13 by tturner           #+#    #+#             */
/*   Updated: 2021/09/07 10:44:13 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	j = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	while (j + destlen < dstsize - 1 && src[j] != '\0' && dstsize != 0)
	{
		dest[destlen + j] = src[j];
		j++;
	}
	dest[destlen + j] = '\0';
	if (destlen >= dstsize)
		destlen = dstsize;
	return (destlen + srclen);
}
