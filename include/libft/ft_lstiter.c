/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:39:11 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/14 14:39:12 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!lst)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* 08
- - Description
Iterates ’lst’ and applies the function ’f’ on the content of each node.
- - Parameters
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
- - Return
N/A
*/