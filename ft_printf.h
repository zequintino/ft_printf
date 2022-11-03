/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquintin <jquintin@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:03:57 by jquintin          #+#    #+#             */
/*   Updated: 2022/10/07 12:59:11 by jquintin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_puts(const char *s);
int	ft_putnbr_base(long long n, char *base);

#endif
