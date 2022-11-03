/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:02:54 by jquintin          #+#    #+#             */
/*   Updated: 2022/10/07 13:21:31 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_valid_base(char *base);

int	ft_putchar(int c)
{
	write(1, &c, sizeof(char));
	return (1);
}

int	ft_puts(const char *s)
{
	int	len;

	len = -1;
	while (s[++len])
		ft_putchar(s[len]);
	return (len);
}

int	ft_putnbr_base(long long n, char *base)
{
	long long	base_len;
	int			str_len;

	str_len = 0;
	base_len = ft_strlen(base);
	if (!check_valid_base(base))
		return (0);
	else
	{
		if (n <= INT_MIN)
			str_len = ft_puts("-2147483648");
		else if (n < 0)
		{
			str_len = ft_putchar('-');
			ft_putnbr_base(-n, base);
		}
		else if (n >= base_len)
		{
			str_len += ft_putnbr_base(n / base_len, base);
			str_len += ft_putnbr_base(n % base_len, base);
		}
		else
			str_len += ft_putchar(base[n]);
	}
	return (str_len);
}

int	check_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (*(base + i))
	{
		j = i + 1;
		if (*(base + i) == '+' || *(base + i) == '-')
			return (0);
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
