/* ************************************************************************** */
/*                                                                            */
/*                                                          :::    ::::::::   */
/*   ft_printf.c                                            :+:    :+:  :+:   */
/*                                                          +:+ +:+     +:+   */
/*   By: dberehov <marvin@42.fr>                          +#+  +:+     +#+    */
/*                                                    +#+#+#+#+#+   +#+       */
/*   Created: 2022/11/21 16:18:58 by dberehov      #+#  #+#                   */
/*   Updated: 2022/11/21 16:19:00 by dberehov     ###   ########.fr           */
/*                                                                            */
/* ************************************************************************** */
/*
Requirements:
☐ Don’t implement the buffer management of the original printf().
☐ Your function has to handle the following conversions: cspdiuxX%
☐ Your function will be compared against the original printf().
☐ You must use the command ar to create your library.
☐ Using the libtool command is forbidden.
☐ Your libftprintf.a has to be created at the root of your repository.
Implement the following conversions:
☑ %c Prints a single character.
☑ %s Prints a string (as defined by the common C convention).
☑ %p The void * pointer argument has to be printed in hexadecimal format.
☑ %d Prints a decimal (base 10) number.
☑ %i Prints an integer in base 10
☑ %u Prints an unsigned decimal (base 10) number.
☑ %x Prints a number in hexadecimal (base 16) lowercase format.
☑ %X Prints a number in hexadecimal (base 16) uppercase format.
☑ %% Prints a percent sign.
Bonus:
☐ Manage any combination of the following flags: ’-0.’ and the field minimum
width under all conversions.
☐ Manage all the following flags: ’# +’ (Yes, one of them is a space)
*/

//%[flags][width][.precision][length]type

#include "includes/ft_printf.h"

//Initialise struct variables
t_format	*init_specifier(t_format *spec)
{
	spec->bt_length = 0;
	return (spec);
}

//So far will catch only conversions
void	catch_format(va_list args, const char c, t_format *spec)
{
	if (c == 'c')
		print_chr(va_arg(args, int), spec);
	else if (c == 's')
		print_str(va_arg(args, char *), spec);
	else if (c == 'd' || c == 'i')
		print_num(va_arg(args, int), spec);
	else if (c == 'p')
		print_ptr(va_arg(args, unsigned long long), spec);
	else if (c == 'u')
		print_uns(va_arg(args, unsigned int), spec);
	else if (c == 'x')
		print_hex(va_arg(args, int), spec, "0123456789abcdef");
	else if (c == 'X')
		print_hex(va_arg(args, int), spec, "0123456789ABCDEF");
	else if (c == '%')
		spec->bt_length += write(1, "%", 1);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_format	*spec;
	int			i;

	spec = (t_format *)malloc(sizeof(t_format));
	if (!spec)
		return (-1);
	init_specifier(spec);
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			catch_format(args, format[i + 1], spec);
			i++;
		}
		else
			spec->bt_length += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	i = spec->bt_length;
	free (spec);
	return (i);
}
