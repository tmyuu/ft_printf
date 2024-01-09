/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:18:47 by ymatsui           #+#    #+#             */
/*   Updated: 2024/01/09 13:46:50 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_print_percent(va_list *args)
{
	size_t	len;

	len = 1;
	(void)args;
	write(1, "%", 1);
	return (len);
}

t_format	create_percent_format(void)
{
	t_format	format;

	format.specifier = '%';
	format.print_func = ft_print_percent;
	return (format);
}
