/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:50:12 by dberehov          #+#    #+#             */
/*   Updated: 2022/11/11 19:50:13 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

/* 09
- - Description
Outputs the string ’s’ to the given file descriptor.
- - Parameters
s: The string to output.
fd: The file descriptor on which to write.
- - Return
N/A
*/