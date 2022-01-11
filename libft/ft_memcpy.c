/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 09:40:01 by marvin            #+#    #+#             */
/*   Updated: 2022/01/10 18:24:23 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*a;
	const char	*b;

	a = dest;
	b = src;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}
