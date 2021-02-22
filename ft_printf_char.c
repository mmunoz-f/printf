/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:06:50 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/22 19:17:17 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_printf_char(t_format *format, char **str)
{
	unsigned int	width;
	unsigned int	count;

	count = 0;
	width = 0;
	if (format->flags[1])
		width = ft_atoi(format->flags[1]);
	if (width > 1)
	{
		if (format->flags[0])
		{
			if (ft_strchr(format->flags[0], '-'))
			{
				count = ft_putchar_fd(**str, 1);
				count += put_padding(1, width, ' ');
				return (count);
			}
			else if (ft_strchr(format->flags[0], '0'))
				count = put_padding(1, width, '0');
		}
		else
			count = put_padding(1, width, ' ');
	}
	count += ft_putchar_fd(**str, 1);
	return (count);
}
