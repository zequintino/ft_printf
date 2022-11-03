/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:15:00 by jquintin          #+#    #+#             */
/*   Updated: 2022/10/07 13:12:03 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_conv_flags(const char c, va_list ptr);

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		len;
	int		i;

	va_start(ptr, str);
	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i]);
		else
		{
			len += check_conv_flags(str[i + 1], ptr);
			i++;
		}
	}
	va_end(ptr);
	return (len);
}

int	check_conv_flags(const char c, va_list ptr)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	else if (c == 's')
		return (ft_puts(va_arg(ptr, char *)));
	else if (c == 'p')
	{
		ft_puts("0x");
		return (ft_putnbr_base((long long)va_arg(ptr, void *),
				"0123456789abcdef") + 2);
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(ptr, int), "0123456789"));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(ptr, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}
