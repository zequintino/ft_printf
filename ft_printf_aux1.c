/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:02:54 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/04 17:53:42 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc(int c);
int	ft_puts(const char *s);

int	check_conv_flags(const char c, va_list ptr)
{
	if (c == 'c')
		return (ft_putc(va_arg(ptr, int)));
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
		return (ft_putc('%'));
	return (0);
}

int	ft_putc(int c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int	ft_puts(const char *s)
{
	int	len;

	if (!s)
	{
		len = 0;
		return (len += ft_puts("(null)"));
	}
	len = -1;
	while (s[++len])
		ft_putc(s[len]);
	return (len);
}
