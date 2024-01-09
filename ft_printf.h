/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymatsui <ymatsui@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:38:26 by ymatsui           #+#    #+#             */
/*   Updated: 2024/01/09 13:00:45 by ymatsui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_format
{
	char	specifier;
	size_t	(*ft_printf)(va_list *args);
}			t_format;

size_t		ft_print_char(va_list *args);
t_format	create_char_format(void);

size_t		ft_print_str(va_list *args);
t_format	create_str_format(void);

size_t		ft_puthex(uintptr_t ptr);
size_t		ft_print_address(va_list *args);
t_format	create_address_format(void);

size_t		ft_putnbr_decimal(int n);
size_t		ft_print_decimal(va_list *args);
t_format	create_decimal_format(void);

size_t		ft_putnbr_int(int n);
size_t		ft_print_int(va_list *args);
t_format	create_int_format(void);

size_t		ft_putnbr_unsigned_decimal(unsigned int n);
size_t		ft_print_unsigned_decimal(va_list *args);
t_format	create_unsigned_decimal_format(void);

size_t		ft_puthex_lower(unsigned int n);
size_t		ft_print_hex_lower(va_list *args);
t_format	create_hex_lower_format(void);

size_t		ft_puthex_upper(unsigned int n);
size_t		ft_print_hex_upper(va_list *args);
t_format	create_hex_upper_format(void);

size_t		ft_print_percent(va_list *args);
t_format	create_percent_format(void);

void		ft_check_specifier(const char *format, t_format *fmt_struct);
int			ft_printf(const char *format, ...);

#endif
