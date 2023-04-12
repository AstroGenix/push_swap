/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:39:24 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/14 14:39:25 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*new_list;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
			ft_lstclear(&new_list, del);
		if (!temp)
			return (NULL);
		ft_lstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}

/* 09
- - Description
Iterates ’lst’ and applies the function ’f’ on the content of each node.
Creates a new list resulting of the successive applications of function ’f’.
The ’del’ function is used to delete the content of a node if needed.
- - Parameters
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
del: The address of the func used to delete the content of a node if needed.
- - Return
The new list.
NULL if the allocation fails.
*/