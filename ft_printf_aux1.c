/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:02:54 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/07 17:48:46 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_flags(const char c, va_list ptr)
{
	if (c == 'c')
		return (ft_putchr(va_arg(ptr, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	else if (c == 'p')
		return (ft_check_ptr(va_arg(ptr, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(ptr, int), "0123456789"));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchr('%'));
	return (0);
}

int	ft_check_ptr(long long n)
{
	if (!n)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_putnbr_ptr(n, "0123456789abcdef") + 2);
}
