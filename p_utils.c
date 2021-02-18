/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:13:30 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/18 18:53:35 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					p_addchr(char **s, char c)
{
	char	new[2];
	char	*temp;

	new[0] = c;
	new[1] = 0;
	temp = *s;
	if (!(*s = ft_strjoin(*s, new)))
		return (0);
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

char				*ft_lunsigned_itoa(long unsigned int n)
{
	char				*str;
	long unsigned int	size;

	size = ft_unslength(n, 10);
	if (!(str = (char *)malloc(size + 1)))
		return (0);
	str[size] = 0;
	if (n == 0)
		str[--size] = '0';
	while (n)
	{
		str[--size] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}

char				*ft_ptrtostr(long unsigned int n, char *base)
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
