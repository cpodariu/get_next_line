/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:10:51 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 17:03:26 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int rez;

	if (!(*s) || !s)
		return (NULL);
	rez = 0;
	while (*s)
	{
		if (!ft_isascii(*s))
			return (NULL);
		if (*s == (char)c)
			rez = 0;
		rez++;
		s++;
	}
	if (c == 0)
		return ((char*)s);
	return (&(((char *)s)[-rez]));
}
