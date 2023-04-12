/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pntr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:09:27 by dberehov          #+#    #+#             */
/*   Updated: 2022/12/02 17:09:28 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// p - Arithmetics of ptr
void	ptr_arithm(unsigned long num)
{
	if (num >= 16)
	{
		ptr_arithm(num / 16);
		ptr_arithm(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

// p - Memory lenght return
int	ptr_length(unsigned long num)
{
	int	ptr_len;

	ptr_len = 0;
	while (num != 0)
	{
		ptr_len++;
		num = num / 16;
	}
	return (ptr_len);
}

// p - Prints a memory
t_format	print_ptr(unsigned long ptr, t_format *spec)
{
	if (ptr == 0)
		spec->bt_length += write(1, "(nil)", 5);
	if (ptr == 0)
		return (*spec);
	spec->bt_length += write(1, "0x", 2);
	ptr_arithm(ptr);
	spec->bt_length += ptr_length(ptr);
	return (*spec);
}
