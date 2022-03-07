/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:51:36 by tturner           #+#    #+#             */
/*   Updated: 2021/09/17 17:51:36 by tturner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	return (0);
}

static long	chartoint(int neg, char *num, int len)
{
	long	rtn;
	int		power;

	power = 1;
	rtn = 0;
	while (len > 0)
	{
		rtn += (num[len - 1] - '0') * power;
		power = power * 10;
		len--;
	}
	if (neg)
		rtn = -rtn;
	return (rtn);
}

long	ft_atoi(const char *nptr)
{
	int		i;
	int		j;
	int		neg;
	char	num[10];

	i = 0;
	j = 0;
	neg = 0;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg++;
		i++;
	}
	if (nptr[i] >= '0' && nptr[i] <= '9')
	{
		while (nptr[i] >= '0' && nptr[i] <= '9')
			num[j++] = nptr[i++];
		return (chartoint(neg, num, j));
	}
	return (0);
}

int	ft_is_valid(char *str)
{
	int		i;
	int		len;
	long	num;

	len = ft_strlen(str);
	num = ft_atoi(str);
	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-')
			return (0);
		i++;
	}
	if (len > 11 || num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}
