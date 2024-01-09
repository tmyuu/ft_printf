/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:57:07 by ymatsui           #+#    #+#             */
/*   Updated: 2024/01/09 13:47:06 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_decimal(int n)
{
	size_t	len;
	char	digit;

	len = 0;
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		len = 11;
		return (len);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		len++;
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr_decimal(n / 10);
	digit = n % 10 + '0';
	write(1, &digit, 1);
	len += 1;
	return (len);
}

size_t	ft_print_decimal(va_list *args)
{
	size_t	len;
	int		n;

	len = 0;
	n = va_arg(*args, int);
	len = ft_putnbr_decimal(n);
	return (len);
}

t_format	create_decimal_format(void)
{
	t_format	format;

	format.specifier = 'd';
	format.print_func = ft_print_decimal;
	return (format);
}
