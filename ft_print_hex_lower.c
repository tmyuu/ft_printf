/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:43:25 by ymatsui           #+#    #+#             */
/*   Updated: 2024/01/09 13:47:02 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthex_lower(unsigned int n)
{
	size_t	len;
	char	digit;

	len = 0;
	if (n >= 16)
		len += ft_puthex_lower(n / 16);
	digit = n % 16;
	if (digit >= 0 && digit < 10)
		digit = '0' + digit;
	else
		digit = 'a' + digit - 10;
	write(1, &digit, 1);
	len += 1;
	return (len);
}

size_t	ft_print_hex_lower(va_list *args)
{
	size_t			len;
	unsigned int	n;

	len = 0;
	n = va_arg(*args, unsigned int);
	len = ft_puthex_lower(n);
	return (len);
}

t_format	create_hex_lower_format(void)
{
	t_format	format;

	format.specifier = 'x';
	format.print_func = ft_print_hex_lower;
	return (format);
}
