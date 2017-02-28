/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:06:51 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 17:33:02 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int l;

	l = 0;
	while (n)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

static int	is_negative(int *n)
{
	if (*n == -2147483648)
		return (-1);
	if (*n < 0)
	{
		*n = -(*n);
		return (1);
	}
	return (0);
}

char		*ft_itoa(int n)
{
	int		l;
	int		is_neg;
	char	*str;

	is_neg = is_negative(&n);
	l = numlen(n) + is_neg;
	str = ft_strnew(l + is_neg);
	if (!str)
		return (NULL);
	if (is_neg == -1)
		return (ft_strcpy(str, "-2147483648"));
	if (n == 0)
		return (ft_strcpy(str, "0"));
	str[l] = 0;
	while (l >= is_neg)
	{
		str[l - 1] = n % 10 + '0';
		n = n / 10;
		l--;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}
