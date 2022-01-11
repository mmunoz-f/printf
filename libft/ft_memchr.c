/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:18:30 by marvin            #+#    #+#             */
/*   Updated: 2022/01/10 18:25:00 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *src, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	i = 0;
	a = src;
	while (i < n)
	{
		if (a[i] == (unsigned char)c && i < n)
			return (&a[i]);
		i++;
	}
	return (0);
}
