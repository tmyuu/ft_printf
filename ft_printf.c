/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:14:04 by ymatsui           #+#    #+#             */
/*   Updated: 2024/01/09 14:09:57 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_specifier(const char *format, t_format *fmt_struct)
{
	if (*format && *format == 'c')
		*fmt_struct = create_char_format();
	else if (*format && *format == 's')
		*fmt_struct = create_str_format();
	else if (*format && *format == 'p')
		*fmt_struct = create_address_format();
	else if (*format && *format == 'd')
		*fmt_struct = create_decimal_format();
	else if (*format && *format == 'i')
		*fmt_struct = create_int_format();
	else if (*format && *format == 'u')
		*fmt_struct = create_unsigned_decimal_format();
	else if (*format && *format == 'x')
		*fmt_struct = create_hex_lower_format();
	else if (*format && *format == 'X')
		*fmt_struct = create_hex_upper_format();
	else if (*format && *format == '%')
		*fmt_struct = create_percent_format();
}

int	ft_printf(const char *format, ...)
{
	size_t		len;
	va_list		args;
	t_format	fmt_struct;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_check_specifier(format, &fmt_struct);
			len += fmt_struct.print_func(&args);
		}
		else
		{
			write(1, format, 1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	ft_printf("%d", -4294967346);
// 	return (0);
// }
