/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:39:20 by ymatsui           #+#    #+#             */
/*   Updated: 2024/01/09 12:27:13 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_char(va_list *args)
{
	size_t	len;
	char	c;

	len = 1;
	c = (char)va_arg(*args, int);
	write(1, &c, 1);
	return (len);
}

t_format	create_char_format(void)
{
	t_format	format;

	format.specifier = 'c';
	format.ft_printf = ft_print_char;
	return (format);
}
