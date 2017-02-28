/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:12:11 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 16:23:20 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(char const *str, char c)
{
	int words;

	words = 0;
	while (1)
	{
		while (*str == c)
			str++;
		if (!(*str))
			return (words);
		words++;
		while (*str && *str != c)
			str++;
	}
}

static char	*ft_get_next_word(char **str, char c)
{
	char *begining;

	while (**str == c)
		(*str)++;
	begining = *str;
	while (**str && **str != c)
		(*str)++;
	**str = 0;
	(*str)++;
	return (begining);
}

static void	ft_make_matrix(char **ret, const char *str, char c, int len)
{
	int		i;
	char	*cpy;

	cpy = ft_strdup(str);
	i = 0;
	while (i < len)
	{
		ret[i] = ft_get_next_word(&cpy, c);
		i++;
	}
	ret[i] = NULL;
}

char		**ft_strsplit(char const *str, char c)
{
	char	**ret;
	int		len;

	if (!str)
		return (NULL);
	len = ft_count_words(str, c);
	if (!(ret = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	if (!ret)
		return (NULL);
	ft_make_matrix(ret, str, c, len);
	return (ret);
}
