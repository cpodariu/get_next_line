/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:58:05 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 16:55:18 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *p;

	if (!s)
		return (NULL);
	p = (unsigned char*)s;
	while (n)
	{
		*p = (unsigned char)c;
		p++;
		n--;
	}
	return (s);
}
