/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:52:00 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/20 20:00:16 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_flag(char **format, char flag)
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

void	format_precision(char **str, t_format *format)
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
			return ;
		}
		if (len < precision)
			p_addchr(str, '0', precision - len, 1);
	}
	if (format->specifier == 's')
	{
		temp = *str;
		*str = ft_substr(*str, 0, precision);
		free(temp);
	}
}

void	format_width(char **str, t_format *format)
{
	unsigned int	len;
	unsigned int	width;

	len = ft_strlen(*str);
	width = 0;
	if (format->flags[1])
		width = ft_atoi(format->flags[1]);
	if (format->flags[0])
	{
		if (ft_strchr(format->flags[0], '-') && len < width)
			p_addchr(str, ' ', width - len, 0);
		else if (ft_strchr(format->flags[0], '0') && len < width)
			p_addchr(str, '0', width - len, 1);
	}
	else if (len < width)
		p_addchr(str, ' ', width - len, 1);
}
