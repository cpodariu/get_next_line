/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:30:59 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 17:32:44 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	p = (char *)s;
	i = 0;
	while (*p && *p != c && i < n)
	{
		p++;
		i++;
	}
	if (i == n)
		return (NULL);
	return ((void *)p);
}
