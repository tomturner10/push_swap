/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:54:32 by tturner           #+#    #+#             */
/*   Updated: 2021/09/07 16:54:32 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*rtn;
	int		beg;
	int		end;
	int		i;

	i = 0;
	beg = 0;
	end = ft_strlen(s1) - 1;
	if (set == NULL)
		return (ft_strdup(s1));
	while (s1[beg] != '\0' && ft_strchr(set, s1[beg]) != NULL)
		beg++;
	while (end > beg && ft_strchr(set, s1[end]) != NULL)
		end--;
	rtn = (char *)malloc((end + 2 - beg) * sizeof(char));
	if (rtn == NULL)
		return (NULL);
	while (i <= end - beg)
	{
		rtn[i] = s1[beg + i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
