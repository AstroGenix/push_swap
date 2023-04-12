/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:39:00 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/14 14:39:01 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}

/* 07
- - Description
Deletes and frees the given node and every successor of that node,
using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
- - Parameters
lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.
- - Return
N/A
*/