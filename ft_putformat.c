/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:54:24 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/19 20:36:37 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_width(char **format, char *str, va_list ap)
{
	char	*temp;

	if (!*format)
	{
		if (!(*format = ft_strdup("")))
			return (0);
	}
	temp = *format;
	if (*str == '*')
	{
		if (!(*format = ft_itoa(va_arg(ap, int))))
			return (0);
	}
	else
	{
		if (!(*format = ft_strdup(ft_atoi(str))))
			return (0);
	}
	free(temp);
	return (1);
}

int		set_precision(char **format, char *str, va_list ap)
{
	char	*temp;

	if (!*format)
	{
		if (!(*format = ft_strdup("")))
			return (0);
	}
	temp = *format;
	if (*(++str) == '*')
	{
		if (!(*format = ft_itoa(va_arg(ap, int))))
			return (0);
	}
	else
	{
		if (!(*format = ft_strdup(ft_atoi(str))))
			return (0);
	}
	free(temp);
	return (1);
}

int		set_length(char **format, char *str)
{
	if (!*format)
	{
		if (!(*format = ft_strdup("")))
			return (0);
	}
	return (1);
}

char	*start_str(char specifier, va_list ap)
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
		return (0);
}

int		ft_putformat(t_format *format, va_list ap)
{
	char			*str;
	char			*temp;
	unsigned int	i;

	if (!(str = start_str(format->specifier, ap)))
		return (0);
	if (ft_strchar(format->flags[0], '-'))
		minus_flag_format(str, format);
	else if (ft_strchr(format->flags[0], '0'))
		zero_flag_format(str, format);
	return (ft_putstr_fd(str, 1));
}
