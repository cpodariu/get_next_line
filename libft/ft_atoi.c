/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:29:52 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 17:30:12 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ret_rez(const char *str, int sign)
{
	long nbr;

	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
		if (sign == -1 && nbr > 2147483648)
			return (0);
		if (sign == 1 && nbr > 2147483647)
			return (-1);
	}
	return ((int)(sign * nbr));
}

int			ft_atoi(const char *str)
{
	char	is_neg;

	while (*str == '\n' || *str == ' ' || *str == '\t' || *str == '\b' ||
			*str == '\f' || *str == '\r' || *str == '\v')
		str++;
	is_neg = 1;
	if (*str == '-')
		is_neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	return (ret_rez(str, is_neg));
}
