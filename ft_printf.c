/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 18:15:00 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/04 13:13:23 by jquintin         ###   ########.fr       */
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
			len += ft_putc(str[i]);
		else
		{
			len += check_conv_flags(str[i + 1], ptr);
			i++;
		}
	}
	va_end(ptr);
	return (len);
}
