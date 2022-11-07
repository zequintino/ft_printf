/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:03:57 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/07 17:37:06 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_putchr(int c);
int	ft_putstr(const char *s);
int	ft_conv_flags(const char c, va_list ptr);
int	ft_check_ptr(long long n);
int	ft_putnbr_ptr(unsigned long long n, char *base);
int	ft_putnbr_base(long long n, char *base);

#endif
