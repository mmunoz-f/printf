/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:32:02 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/16 18:50:05 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_format	*init_format()
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

int			fill_flag(char *fmt, char **flag)
{
	int	count;

	count = 0;
	if (*fmt == '*')
	{
		if (!(p_addchr(flag, '*')))
			return (0);
		return (++count);
	}
	while (*fmt >= '0' && *fmt <= '9')
	{
		if (!(p_addchr(flag, *fmt)))
			return (0);
		fmt++;
		count++;
	}
	if (*fmt == '*')
		return (0);
	return (count);
}

t_format	*setformat(char *fmt, va_list ap)// 26 lineas
{
	t_format		*format;
	int				i;

	if (!(format = init_format()))
		return (0);
	i = 0;
	while (!ft_strchr("cspdiuxX%", *fmt) && *fmt)
	{
		if (!ft_strchr("-0.*123456789", *fmt))
			return (0);
		if (ft_strchr("0-", *fmt) && !i)
		{
			if (!(p_addchr(&format->flags[0], *fmt)))
				return (0);
		}
		if (ft_strchr(".123456789*", *fmt) && i++ < 3)
		{
			if (*(fmt++) = '.')//probablemente tengas que incluir esto en la funcion fill_flag()
				i++;
			if (!(fill_flag(fmt, &format->flags[i++])))//Guarda el valor que le corresponde a width o precision, cuidado con los *, no pueden estar detras de un numero
				return (0);
		}
		fmt++;
	}
	format->specifier = *fmt;//puede llegar a guardar el valor '/0' en este caso deberiamos devolver error mas adelante al intentar leer el tipo
	return (format);
}

int			ft_printf(const char *fmt, ...)//18 lines
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
		//Detecta siempre los %, no esta implementado que sean escapados
		if (*fmt == '%')
			format = setformat(fmt, ap_copy);
		ft_putchar_fd(*fmt, 1);
		count++;
		fmt++;
	}
	va_end(ap);
	return (count);
}
