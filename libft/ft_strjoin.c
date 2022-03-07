/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:54:31 by tturner           #+#    #+#             */
/*   Updated: 2021/09/07 16:54:31 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*rtn;
	unsigned int	s1len;
	unsigned int	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	rtn = (char *)malloc((s1len + s2len) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	ft_strlcpy(rtn, (char *)s1, s1len + 1);
	ft_strlcat(rtn, s2, s1len + s2len + 1);
	return (rtn);
}
