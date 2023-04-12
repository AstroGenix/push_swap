/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:09:11 by dberehov          #+#    #+#             */
/*   Updated: 2022/12/02 17:09:12 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// x - Hexadecimal arithmetics.
void	hex_arithm(unsigned int num, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	if (num < i)
		ft_putchar_fd(base[num], 1);
	if (num >= i)
	{
		hex_arithm(num / i, base);
		hex_arithm(num % i, base);
	}
}

// x - Prints a hex value
t_format	print_hex(unsigned int num, t_format *spec, char *convert)
{
	unsigned int	num_conv;

	num_conv = num;
	if (num_conv == 0)
		spec->bt_length += write(1, "0", 1);
	if (num_conv == 0)
		return (*spec);
	while (num_conv != 0)
	{
		num_conv /= 16;
		spec->bt_length++;
	}
	hex_arithm(num, convert);
	return (*spec);
}
