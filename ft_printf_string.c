/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:30:46 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/22 20:18:58 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	put_padding(unsigned int len, unsigned int width, char c)
{
	unsigned int	count;

	count = 0;
	while (len++ < width)
	{
		ft_putchar_fd(c, 1);
		count++;
	}
	return (count);
}

unsigned int	put_string(char **str, t_format *format)
{
	unsigned int	count;
	unsigned int	len;
	unsigned int	width;

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
			{
				count = ft_putstr_fd(*str, 1);
				count += put_padding(len, width, ' ');
				return (count);
			}
		}
		else
			count = put_padding(len, width, ' ');
	}
	count += ft_putstr_fd(*str, 1);
	return (count);
}

unsigned int	ft_printf_string(t_format *format, char **str)
{
	char			*temp;
	unsigned int	precision;

	if (*str == 0)
		*str = ft_strdup("(null)");
	if (format->flags[2])
	{
		precision = ft_atoi(format->flags[2]);
		temp = *str;
		*str = ft_substr(*str, 0, precision);
		free(temp);
	}
	return (put_string(str, format));
}
