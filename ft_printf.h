/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:34:07 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/22 19:22:26 by mmunoz-f         ###   ########.fr       */
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

t_format		*init_format(void);

int				set_width(char **format, const char *str, va_list ap);

int				set_precision(char **format, const char *str, va_list ap);

int				set_length(char **format, const char *str);

int				set_flag(char **format, char flag);

unsigned int	ft_printf_string(t_format *format, char **str);

unsigned int	ft_printf_char(t_format *format, char **str);

unsigned int	ft_printf_pointer(t_format *format, char **str);

unsigned int	ft_printf_number(t_format *format, char **str);

unsigned int	put_padding(unsigned int len, unsigned int width, char c);

unsigned int	minus_flag(char *str, unsigned int l, unsigned int w);

#endif
