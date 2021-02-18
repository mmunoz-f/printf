/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:32:02 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/18 19:50:37 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_format	*init_format(void)
{
	t_format		*format;
	unsigned int	i;

	i = 0;
	if (!(format = (t_format *)malloc(sizeof(t_format))))
		return (0);
	while (i < 4)
	{
		if (!(format->flags[i] = ft_strdup("")))
			return (0);
		i++;
	}
	return (format);
}

int			fill_flag(const char **fmt, char **flag)
{
	if (**fmt == '*')
	{
		if (!(p_addchr(flag, '*')))
			return (0);
		return (1);
	}
	while (**fmt >= '0' && **fmt <= '9')
	{
		if (!(p_addchr(flag, **fmt)))
			return (0);
		(*fmt)++;
	}
	if (**fmt == '*')
		return (0);
	return (1);
}

t_format	*setformat(const char **fmt)
{
	t_format		*format;
	int				i;

	if (!(format = init_format()))//Puedes intentar quitar el return 0 en este caso y proteger las funciones que emplean format(con proteger la primera bastaria)
		return (0);
	i = 0;
	while (!ft_strchr("cspdiuxX%", **fmt) && **fmt)
	{
		if (!ft_strchr("-0.*123456789", **fmt))
			return (0);
		if (ft_strchr("0-", **fmt) && !i)
		{
			if (!(p_addchr(&format->flags[0], **fmt)))
				return (0);
		}
		else if (ft_strchr(".123456789*", **fmt) && i < 3)
		{
			if (*((*fmt)++) == '.')//probablemente tengas que incluir esto en la funcion fill_flag()
				i++;
			if (!(fill_flag(fmt, &format->flags[++i])))
				return (0);
		}
		(*fmt)++;
	}
	format->specifier = **fmt;
	return (format);
}

int			ft_printf(const char *fmt, ...)
{
	va_list			ap;
	va_list			ap_copy;
	t_format		*format;
	unsigned int	count;

	va_start(ap, fmt);
	va_copy(ap_copy, ap);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			format = setformat(&(fmt));
			count += ft_putformat(format, ap_copy);
			fmt++;
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			count++;
			fmt++;
		}
	}
	va_end(ap_copy);
	va_end(ap);
	return (count);
}
