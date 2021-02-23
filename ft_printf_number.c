/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:17:42 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/23 17:19:51 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_precision(char **str, t_format *format, int n)
{
	unsigned int	precision;
	unsigned int	len;
	char			*temp;

	if (format->flags[2])
	{
		precision = ft_atoi(format->flags[2]);
		len = ft_strlen(*str);
	}
	else
	{
		precision = ft_atoi(format->flags[1]);
		len = ft_strlen(*str) + n;
	}
	if (**str == '0' && precision == 0 && format->flags[2])
	{
		temp = *str;
		*str = ft_strdup("");
		free(temp);
	}
	else if (len < precision)
		p_addchr(str, '0', precision - len, 1);
}

unsigned int	put_number(char **str, t_format *format)
{
	unsigned int	count;
	unsigned int	width;
	unsigned int	len;

	count = 0;
	width = 0;
	len = ft_strlen(*str);
	if (format->flags[1])
		width = ft_atoi(format->flags[1]);
	if (len < width)
	{
		if (format->flags[0])
		{
			if (ft_strchr(format->flags[0], '-'))
				return (minus_flag(*str, len, width));
		}
		count = put_padding(len, width, ' ');
	}
	count += ft_putstr_fd(*str, 1);
	return (count);
}

unsigned int	ft_printf_number(t_format *format, char **str)
{
	unsigned int	count;
	int				n;
	char			*temp;

	count = 0;
	n = 0;
	if (**str == '-')
	{
		n = 1;
		temp = *str;
		*str = ft_strdup(*str + 1);
		free(temp);
	}
	if (format->flags[2] || (ft_strchr(format->flags[0], '0')
		&& !format->flags[2] && !(ft_strchr(format->flags[0], '-'))
			&& format->flags[1]))
		format_precision(str, format, n);
	if (n)
		p_addchr(str, '-', 1, 1);
	count += put_number(str, format);
	return (count);
}
