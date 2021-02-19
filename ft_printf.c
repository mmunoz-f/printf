/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:32:02 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/19 20:32:41 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*init_format(void)
{
	t_format		*format;
	unsigned int	i;

	i = 0;
	if (!(format = (t_format *)malloc(sizeof(t_format))))
		return (0);
	while (i < 4)
	{
		format->flags[i] = 0;
		i++;
	}
	return (format);
}

t_format	*setformat(const char **fmt, va_list ap)
{
	t_format		*format;
	int				i;

	if (!(format = init_format()))
		return (0);
	i = 0;
	while (!ft_strchr("cspdiuxX%", **fmt) && **fmt)
	{
		if (ft_strchr("123456789*", **fmt)
			&& (*(*fmt - 1) < '0' || *(*fmt - 1) > '9') && *(*fmt - 1) != '.')
			set_width(&format->flags[1], *fmt, ap);
		if (**fmt == '.')
			set_precision(&format->flags[2], *fmt, ap);
		if (ft_strchr("-", **fmt))
			set_flag(&format->flags[0], **fmt);
		if (**fmt == '0' && (*(*fmt - 1) < '0' || *(*fmt - 1) > '9'))
			set_flag(&format->flags[0], '0');
		if (ft_strchr("", **fmt))
			set_length(&format->flags[3], *fmt);
		(*fmt)++;
	}
	format->specifier = **fmt;
	return (format);
}

int			ft_printf(const char *fmt, ...)
{
	va_list			ap;
	t_format		*format;
	unsigned int	count;

	va_start(ap, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			format = setformat(&(fmt), ap);
			count += ft_putformat(format, ap);
			fmt++;
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			count++;
			fmt++;
		}
	}
	va_end(ap);
	return (count);
}
