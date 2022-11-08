/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:02:54 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/08 00:59:56 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check_flags(const char c, va_list ap)
{
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		return (1);
	}
	else if (c == 's')
		return (ft_check_s(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_check_p(va_arg(ap, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789"));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_check_s(const char *s)
{
	int	str_len;

	if (!s)
	{
		str_len = 6;
		ft_putstr_fd("(null)", 1);
		return (str_len);
	}
	ft_putstr_fd((char *)s, 1);
	return (ft_strlen(s));
}

int ft_check_p(long long n)
{
	if (!n)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	return (ft_putptr(n, "0123456789abcdef") + 2);
}

int	ft_putptr(unsigned long long n, char *base)
{
	unsigned int	base_len;
	int				str_len;

	str_len = 0;
	base_len = ft_strlen(base);
	if (n / base_len > 0)
		str_len += ft_putnbr_base(n / base_len, base);
	ft_putchar_fd(base[n % base_len], 1);
	str_len += 1;
	return (str_len);
}

int	ft_putnbr_base(long long n, char *base)
{
	unsigned int	base_len;
	int				str_len;

	str_len = 0;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', 1);
		str_len += 1;
	}
	if (n / base_len > 0)
		str_len += ft_putnbr_base(n / base_len, base);
	ft_putchar_fd(base[n % base_len], 1);
	str_len += 1;
	return (str_len);
}
