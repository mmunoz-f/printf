/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:54:24 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/17 15:20:19 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*start_str(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (ft_chartostr(va_arg(ap, char)));//funcion que falta en p_utils.c
	else if (specifier == 's')
		return (ft_strdup(va_arg(ap, char *)));
	else if (specifier == 'p')
		return (ft_ptrtostr(va_arg(ap, void *)));//funcion que falta en p_utils.c
	else if (specifier == 'd' || specifier == 'd')
		return (ft_itoa(va_arg(ap, int)));
	else if (specifier == 'u')
		return (ft_unsigned_itoa(va_arg(ap, unsigned int)));//mejorar itoa o crear uno nuevo
	else if (specifier == 'x')
		return (ft_itoa_base(va_arg(ap, int), "0123456789abcdef"));
	else if (specifier == 'X')
		return (ft_itoa_base(va_arg(ap, int), "0123456789ABCDEF"));
	else
		return (0);
}

int		ft_putformat(t_format format, va_list ap)
{
	char			*str;

	if (!(str = start_str(format.specifier, ap)))
		return (0);
	return (ft_putstr_fd(str, 1));
}