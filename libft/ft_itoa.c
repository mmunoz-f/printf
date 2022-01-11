/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:48:12 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/11 14:21:16 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nlength(int n)
{
	size_t	i;

	i = 1;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	size_t			size;
	char			*str;

	size = ft_nlength(n);
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	if (n < 0)
	{
		str[0] = '-';
		nbr = -(unsigned int)n;
	}
	else
		nbr = (unsigned int)n;
	str[size] = 0;
	while (nbr || !(n--))
	{
		str[--size] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (str);
}
