/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:56:57 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 17:01:48 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char *s2;

	if (!dest || !src)
		return (NULL);
	s2 = dest;
	while (*src != 0 && len > 0)
	{
		*dest = *src;
		dest++;
		src++;
		len--;
	}
	while (len > 0)
	{
		*dest = 0;
		dest++;
		len--;
	}
	return (s2);
}
