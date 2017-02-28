/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpodariu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:31:14 by cpodariu          #+#    #+#             */
/*   Updated: 2017/01/17 17:31:16 by cpodariu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*begin;

	if (!lst)
		return (NULL);
	if (!(new_list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_list = f(lst);
	begin = new_list;
	while (lst->next)
	{
		if (!(new_list->next = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		lst = lst->next;
		new_list->next = f(lst);
		new_list = new_list->next;
	}
	return (begin);
}
