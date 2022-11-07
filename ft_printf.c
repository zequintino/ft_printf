/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:15:00 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/07 17:36:14 by jquintin         ###   ########.fr       */
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
			str_len += ft_putchr(str[i]);
		else
		{
			str_len += ft_conv_flags(str[i + 1], ptr);
			i++;
		}
	}
	va_end(ptr);
	return (str_len);
}
