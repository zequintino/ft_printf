/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:03:57 by jquintin          #+#    #+#             */
/*   Updated: 2022/11/08 12:27:18 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_check_fmt(const char c, va_list ap);
int	ft_check_s(const char *s);
int	ft_check_p(long long n);
int	ft_putptr(unsigned long long n, char *base);
int	ft_putnbr_base(long long n, char *base);

#endif
