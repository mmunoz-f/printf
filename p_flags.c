/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:52:00 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/21 18:18:44 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				set_flag(char **format, char flag)
{
	if (!*format)
	{
		if (!(*format = ft_strdup("")))
			return (0);
	}
	if (flag == 0 && ft_strchr(*format, '-'))
		return (1);
	if (!(p_addchr(format, flag, 1, 0)))
		return (0);
	return (1);
}

void			neg_precision_format(char **str, int precision)
{
	char			*temp;
	unsigned int	len;

	temp = *str;
	len = ft_strlen(*str + 1);
	*str = *str + 1;
	p_addchr(str, '0', precision - len, 1);
	free(temp);
	temp = *str;
	p_addchr(str, '-', 1, 1);
	free(temp);
}

void			format_precision(char **str, t_format *format)
{
	unsigned int	len;
	unsigned int	precision;
	char			*temp;

	len = ft_strlen(*str);
	precision = ft_atoi(format->flags[2]);
	if (ft_strchr("diuxX", format->specifier))
	{
		if (**str == '0' && precision == 0)
		{
			temp = *str;
			*str = ft_strdup("");
			free(temp);
		}
		else if (len < precision && **str != '-')
			p_addchr(str, '0', precision - len, 1);
		else if (len < precision)
			neg_precision_format(str, precision);
	}
	else if (format->specifier == 's')
	{
		temp = *str;
		*str = ft_substr(*str, 0, precision);
		free(temp);
	}
}

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

unsigned int	format_width(char **str, t_format *format)
{
	unsigned int	count;
	unsigned int	len;
	unsigned int	width;

	count = 0;
	width = 0;
	if (format->flags[1])
		width = ft_atoi(format->flags[1]);
	len = ft_strlen(*str);
	if (len < width)
	{
		if (format->flags[0])
		{
			if (ft_strchr(format->flags[0], '-'))
			{
				count = ft_putstr_fd(*str, 1);
				count += put_padding(len, width, ' ');
			}
			else if (ft_strchr(format->flags[0], '0') && format->specifier != 's')
			{
				count = put_padding(len, width, '0');
				count += ft_putstr_fd(*str, 1);
			}
		}
		else
		{
			count = put_padding(len, width, ' ');
			count += ft_putstr_fd(*str, 1);
		}
	}
	else
		count = ft_putstr_fd(*str, 1);
	return (count);
}
