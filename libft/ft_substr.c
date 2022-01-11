/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:50:10 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/10 14:19:47 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, size_t start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	total;

	if (!src)
		return (0);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	total = ft_strlen(src);
	if (start >= total)
		start = total;
	i = 0;
	src += start;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
