/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:20:37 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 16:53:34 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *s;

	if (dest == NULL)
		return (NULL);
	s = (unsigned char *)malloc(sizeof(s) * n);
	if (s == NULL)
		return (dest);
	ft_memcpy(s, src, n);
	ft_memcpy(dest, s, n);
	free(s);
	return (dest);
}
