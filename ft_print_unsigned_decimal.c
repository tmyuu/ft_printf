/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:07:55 by ymatsui           #+#    #+#             */
/*   Updated: 2024/01/09 11:14:37 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_unsigned_decimal(unsigned int n)
{
	size_t	len;
	char	digit;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_unsigned_decimal(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
	len += 1;
	return (len);
}

size_t	ft_print_unsigned_decimal(va_list *args)
{
	size_t			len;
	unsigned int	n;

	len = 0;
	n = va_arg(*args, unsigned int);
	len = ft_putnbr_unsigned_decimal(n);
	return (len);
}

t_format	create_unsigned_decimal_format(void)
{
	t_format	format;

	format.specifier = 'u';
	format.ft_printf = ft_print_unsigned_decimal;
	return (format);
}
