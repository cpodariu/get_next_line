/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:14:54 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 16:57:03 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *src_cpy;
	char *dst_cpy;

	if (!dest || !src)
		return (NULL);
	src_cpy = (char *)src;
	dst_cpy = (char *)dest;
	while (n > 0 && *src_cpy != c)
	{
		n--;
		*dst_cpy++ = *src_cpy++;
	}
	if (n > 0)
	{
		*dst_cpy++ = *src_cpy++;
		return ((void *)dst_cpy);
	}
	else
		return (NULL);
}
