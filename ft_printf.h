/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:34:07 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/21 17:24:03 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct	s_format
{
	char	*flags[4];
	char	specifier;
}				t_format;

int				ft_printf(const char *fmt, ...);

int				p_addchr(char **s, char c, unsigned int len, int backw);

char			*ft_chartostr(char c);

char			*ft_lunsigned_itoa(long unsigned int n);

char			*ft_ptrtostr(long unsigned int n, char *base);

int				ft_putformat(t_format *format, va_list ap);

int				set_width(char **format, const char *str, va_list ap);

int				set_precision(char **format, const char *str, va_list ap);

int				set_length(char **format, const char *str);

int				set_flag(char **format, char flag);

void			format_precision(char **str, t_format *format);

unsigned int	format_width(char **str, t_format *format);

#endif
