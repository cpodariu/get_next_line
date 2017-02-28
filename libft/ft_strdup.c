/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:15:23 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 17:33:36 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		l;
	char	*p;

	if (!s)
		return (NULL);
	l = (int)ft_strlen(s);
	if (!(p = (char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	p[l] = '\0';
	while (l >= 0)
	{
		p[l] = s[l];
		l--;
	}
	return (p);
}
