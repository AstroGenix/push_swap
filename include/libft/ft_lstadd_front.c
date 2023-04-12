/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:37:44 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/14 14:37:47 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* 02
- - Description
Adds the node ’new’ at the beginning of the list.
- - Parameters
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.
- - Return
N/A
*/