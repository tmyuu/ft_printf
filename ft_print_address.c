/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:23:38 by ymatsui           #+#    #+#             */
/*   Updated: 2024/01/09 13:47:14 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthex(uintptr_t ptr)
{
	size_t	len;
	char	digit;

	len = 0;
	if (ptr >= 16)
		len += ft_puthex(ptr / 16);
	digit = ptr % 16;
	if (digit >= 0 && digit < 10)
		digit = '0' + digit;
	else
		digit = 'a' + digit - 10;
	write(1, &digit, 1);
	len += 1;
	return (len);
}

size_t	ft_print_address(va_list *args)
{
	size_t		len;
	uintptr_t	ptr;

	len = 0;
	ptr = (uintptr_t)va_arg(*args, void *);
	write(1, "0x", 2);
	len = ft_puthex(ptr) + 2;
	return (len);
}

t_format	create_address_format(void)
{
	t_format	format;

	format.specifier = 'p';
	format.print_func = ft_print_address;
	return (format);
}
