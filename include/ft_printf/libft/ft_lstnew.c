/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:37:28 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/14 14:37:30 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* 01
- - Description
Allocates (with malloc(3)) and returns a new node. The member variable
’content’ is initialized with the value of the parameter ’content’.
The variable ’next’ is initialized to NULL.
- - Parameters
content: The content to create the node with.
- - Return
The new node.
*/