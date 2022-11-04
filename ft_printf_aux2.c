/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:35:46 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/04 18:03:56 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_valid_base(char *base);

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
		if (n < 0)
		{
			str_len += ft_putc('-');
			str_len += ft_putnbr_base(-n, base);
		}
		else if (n >= base_len)
		{
			str_len += ft_putnbr_base(n / base_len, base);
			str_len += ft_putnbr_base(n % base_len, base);
		}
		else
			str_len += ft_putc(base[n]);
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

/* int	ft_putnbr_base(long long n, char *base)
{
	long long	base_len;
	int			str_len;
	char		tmp[50];
	int			tmp_i;

	str_len = 0;
	tmp_i = 0;
	base_len = ft_strlen(base);
	if (!check_valid_base(base))
		return (0);
	else
	{
		if (n < 0)
		{
			n *= -1;
			str_len += ft_putc('-');
		}
		if (n >= base_len)
		{
			while (n)
			{
				tmp[tmp_i] = base[n % base_len];
				n /= base_len;
				tmp_i++;
			}
		}
		else
			return (str_len += ft_putc(base[n]));
	}
	while (tmp_i > 0)
		str_len += ft_putc(tmp[--tmp_i]);
	return (str_len);
} */
