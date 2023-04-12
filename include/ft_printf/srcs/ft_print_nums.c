/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:08:54 by dberehov          #+#    #+#             */
/*   Updated: 2022/12/02 17:08:55 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

// u - Counts the digits in a number
int	num_count(unsigned int num)
{
	int	count;

	count = 0;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

// d || i - Prints a number
t_format	print_num(int num, t_format *spec)
{
	ft_putnbr_fd(num, 1);
	if (num <= 0)
		spec->bt_length++;
	while (num != 0)
	{
		spec->bt_length++;
		num /= 10;
	}
	return (*spec);
}

// u - Prints an unsigned number
t_format	print_uns(unsigned int num, t_format *spec)
{
	int		i;
	char	*str;

	if (num == 0)
		spec->bt_length += write(1, "0", 1);
	if (num == 0)
		return (*spec);
	i = num_count(num);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (*spec);
	str[i] = '\0';
	while (num > 0)
	{
		i--;
		str[i] = num % 10 + '0';
		num /= 10;
	}
	spec->bt_length += write(1, str, ft_strlen(str));
	free(str);
	return (*spec);
}
