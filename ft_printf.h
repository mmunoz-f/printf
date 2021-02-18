/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:34:07 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/18 18:46:25 by mmunoz-f         ###   ########.fr       */
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

int				p_addchr(char **s, char c);

char			*ft_chartostr(char c);

char			*ft_lunsigned_itoa(long unsigned int n);

char			*ft_ptrtostr(long unsigned int n, char *base);

int				ft_putformat(t_format *format, va_list ap);

#endif
