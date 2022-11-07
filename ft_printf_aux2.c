/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:35:46 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/07 17:48:38 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

int	ft_putchr(int c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int	ft_putstr(const char *s)
{
	int	len;

	if (!s)
	{
		len = 0;
		return (len += ft_putstr("(null)"));
	}
	len = -1;
	while (s[++len])
		ft_putchr(s[len]);
	return (len);
}

int	ft_putnbr_base(long long n, char *base)
{
	unsigned int	base_len;
	int				str_len;

	str_len = 0;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		n = -n;
		str_len += ft_putchr('-');
	}
	if (n / base_len > 0)
		str_len += ft_putnbr_base(n / base_len, base);
	str_len += ft_putchr(base[n % base_len]);
	return (str_len);
}

int	ft_putnbr_ptr(unsigned long long n, char *base)
{
	unsigned int	base_len;
	int				str_len;

	str_len = 0;
	base_len = ft_strlen(base);
	if (n / base_len > 0)
		str_len += ft_putnbr_base(n / base_len, base);
	str_len += ft_putchr(base[n % base_len]);
	return (str_len);
}
