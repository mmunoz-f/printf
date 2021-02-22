/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:27:15 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/22 20:43:04 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			format_pointer(char **str, t_format *format)
{
	unsigned int	precision;
	unsigned int	len;

	len = ft_strlen(*str);
	precision = ft_atoi(format->flags[2]);
	if (len < precision)
		p_addchr(str, '0', precision - len, 1);
}

unsigned int	minus_flag(char *str, unsigned int l, unsigned int w)
{
	unsigned int	count;

	count = ft_putstr_fd(str, 1);
	count += put_padding(l, w, ' ');
	return (count);
}

unsigned int	put_pointer(char **str, t_format *format)
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
			else if (ft_strchr(format->flags[0], '0'))
				count = put_padding(len, width, '0');
		}
		else
			count = put_padding(len, width, ' ');
	}
	else
		count += ft_putstr_fd(*str, 1);
	return (count);
}

unsigned int	ft_printf_pointer(t_format *format, char **str)
{
	unsigned int	count;

	printf("|%s|", *str);//cuidado aqui
	if (format->flags[2])
		format_pointer(str, format);
	printf("|%s|", *str);//same
	p_addchr(str, 'x', 1, 1);
	p_addchr(str, '0', 1, 1);
	count = put_pointer(str, format);
	return (count);
}
