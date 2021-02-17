/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:34:07 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/17 11:49:24 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"

// El array guarda [flags, width, precision, length]
typedef struct	s_format
{
	char	*flags[4];
	char	specifier;
}				t_format;

int				ft_printf(const char *fmt, ...);

int				p_addchr(char **s, char c);

#endif
