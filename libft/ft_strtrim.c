/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 21:49:18 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 17:25:37 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '	' || *s == '\n')
		s++;
	if (*s == '\0')
		return (ft_strdup(""));
	i = 0;
	while (s[i])
		i++;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == 0)
		i--;
	if (!(str = (char *)malloc((i + 2) * sizeof(char))))
		return (ft_strdup(""));
	str[i + 1] = 0;
	while (i >= 0)
	{
		str[i] = s[i];
		i--;
	}
	return (str);
}
