/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:12:30 by ymatsui           #+#    #+#             */
/*   Updated: 2024/01/09 13:46:58 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthex_upper(unsigned int n)
{
	size_t	len;
	char	digit;

	len = 0;
	if (n >= 16)
		len += ft_puthex_upper(n / 16);
	digit = n % 16;
	if (digit >= 0 && digit < 10)
		digit = '0' + digit;
	else
		digit = 'A' + digit - 10;
	write(1, &digit, 1);
	len += 1;
	return (len);
}

size_t	ft_print_hex_upper(va_list *args)
{
	size_t			len;
	unsigned int	n;

	len = 0;
	n = va_arg(*args, unsigned int);
	len = ft_puthex_upper(n);
	return (len);
}

t_format	create_hex_upper_format(void)
{
	t_format	format;

	format.specifier = 'X';
	format.print_func = ft_print_hex_upper;
	return (format);
}
