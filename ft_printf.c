/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:32:02 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/22 20:15:27 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		destroy(t_format *format)
{
	unsigned int	i;

	i = 0;
	if (format)
	{
		while (i < 4)
		{
			if (format->flags[i])
			{
				free(format->flags[i]);
				format->flags[i] = 0;
			}
			i++;
		}
		free(format);
	}
}

char		*start_str(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (ft_chartostr(va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_strdup(va_arg(ap, char *)));
	else if (specifier == 'p')
		return (ft_ptrtostr(va_arg(ap, long unsigned int), "0123456789abcdef"));
	else if (specifier == 'i' || specifier == 'd')
		return (ft_itoa(va_arg(ap, int)));
	else if (specifier == 'u')
		return (ft_lunsigned_itoa((long unsigned int)va_arg(ap, unsigned int)));
	else if (specifier == 'x')
		return (ft_itoa_base(va_arg(ap, int), "0123456789abcdef"));
	else if (specifier == 'X')
		return (ft_itoa_base(va_arg(ap, int), "0123456789ABCDEF"));
	else if (specifier == '%')
		return (ft_chartostr('%'));
	else
		return (ft_strdup(""));
}

int			ft_putformat(t_format *format, va_list ap)
{
	char			*str;
	unsigned int	count;

	count = 0;
	str = start_str(format->specifier, ap);
	if (format->specifier == 's')
		count = ft_printf_string(format, &str);
	else if (format->specifier == 'c' || format->specifier == '%')
		count = ft_printf_char(format, &str);
	else if (format->specifier == 'p')
		count = ft_printf_pointer(format, &str);
	else if (ft_strchr("diuxX", format->specifier))
		count = ft_printf_number(format, &str);
	free(str);
	return (count);
}

t_format	*setformat(const char **fmt, va_list ap)
{
	t_format		*format;
	int				i;

	if (!(format = init_format()))
		return (0);
	i = 0;
	while (ft_strchr("0123456789.*-", **fmt) && **fmt)
	{
		if (ft_strchr("123456789*", **fmt)
			&& (*(*fmt - 1) < '1' || *(*fmt - 1) > '9') && *(*fmt - 1) != '.')
			set_width(&format->flags[1], *fmt, ap);
		else if (**fmt == '.')
			set_precision(&format->flags[2], *fmt, ap);
		else if (ft_strchr("-", **fmt))
			set_flag(&format->flags[0], **fmt);
		else if (**fmt == '0' && (*(*fmt - 1) < '0'
			|| *(*fmt - 1) > '9') && *(*fmt - 1) != '.')
			set_flag(&format->flags[0], '0');
		else if (ft_strchr("", **fmt))
			set_length(&format->flags[3], *fmt);
		(*fmt)++;
	}
	if (ft_strchr("cspdiuxX%", **fmt))
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
			destroy(format);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			count++;
		}
		fmt++;
	}
	va_end(ap);
	return (count);
}
