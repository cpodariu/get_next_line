/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 20:57:22 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/09 20:57:25 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		length;
	char		*out;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	out = NULL;
	if ((start + len) <= length)
	{
		out = (char *)malloc(sizeof(char) * (len + 1));
		if (out)
		{
			out = ft_strncpy(out, s + start, len);
			out[len] = '\0';
		}
	}
	return (out);
}
