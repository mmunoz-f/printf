/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:54:24 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/22 20:29:41 by mmunoz-f         ###   ########.fr       */
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

int			set_flag(char **format, char flag)
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

int			set_width(char **format, const char *str, va_list ap)
{
	char	*temp;

	if (*(str - 1) == '0' && (((*(str - 2) >= '0') && *(str - 2) <= '9')
		|| *(str - 2) == '.'))
		return (0);
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
		if (!(*format = ft_itoa(ft_atoi(str))))
			return (0);
	}
	free(temp);
	return (1);
}

int			set_precision(char **format, const char *str, va_list ap)
{
	char	*temp;

	if (!*format)
	{
		if (!(*format = ft_strdup("0")))
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
		if (!(*format = ft_itoa(ft_atoi(str))))
			return (0);
	}
	if (ft_atoi(*format) < 0)
	{
		free(*format);
		*format = 0;
	}
	free(temp);
	return (1);
}

int			set_length(char **format, const char *str)
{
	if (!*format)
	{
		if (!(*format = ft_strdup("")))
			return (0);
	}
	if (ft_strchr("", *str))
	{
		return (0);
	}
	return (1);
}
