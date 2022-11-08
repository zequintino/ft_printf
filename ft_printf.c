/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:15:00 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/08 14:54:49 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		str_len;
	int		i;

	va_start(ptr, str);
	str_len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			str_len += 1;
		}
		else
		{
			str_len += ft_check_fmt(str[i + 1], ptr);
			i++;
		}
	}
	va_end(ptr);
	return (str_len);
}
