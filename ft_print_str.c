/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:09:15 by ymatsui           #+#    #+#             */
/*   Updated: 2024/01/09 14:39:10 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_str(va_list *args)
{
	size_t	len;
	char	*str;

	len = 0;
	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		len++;
		str++;
	}
	return (len);
}

t_format	create_str_format(void)
{
	t_format	format;

	format.specifier = 's';
	format.print_func = ft_print_str;
	return (format);
}
