/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:13:30 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/23 15:18:31 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				destroy(t_format *format)
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

int					p_addchr(char **s, char c, unsigned int len, int backw)
{
	char	new[len + 1];
	char	*temp;

	new[len] = 0;
	while (len--)
		new[len] = c;
	temp = *s;
	if (!backw)
	{
		if (!(*s = ft_strjoin(*s, new)))
			return (0);
	}
	else
	{
		if (!(*s = ft_strjoin(new, *s)))
			return (0);
	}
	free(temp);
	return (1);
}

char				*ft_chartostr(char c)
{
	char	*str;

	if (!(str = (char *)malloc(2)))
		return (0);
	str[0] = c;
	str[1] = 0;
	return (str);
}

long unsigned int	ft_unslength(long unsigned int n, int base)
{
	long unsigned int	i;

	i = 1;
	while (n / base)
	{
		i++;
		n /= base;
	}
	return (i);
}

char				*ft_lu_itoab(long unsigned int n, char *base)
{
	char				*str;
	unsigned int		type;
	long unsigned int	length;

	type = ft_strlen(base);
	length = ft_unslength(n, type);
	if (!(str = (char *)malloc(length + 1)))
		return (0);
	str[length] = 0;
	if (n == 0)
		str[--length] = '0';
	while (n)
	{
		str[--length] = base[n % type];
		n /= type;
	}
	return (str);
}
