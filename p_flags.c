/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:52:00 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/19 20:30:04 by mmunoz-f         ###   ########.fr       */
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
	if (!(p_addchr(format, flag)))
		return (0);
	return (1);
}

char	*zero_flag_format(char *str)
{

}
