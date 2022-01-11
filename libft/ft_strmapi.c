/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:08:21 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/11 16:25:44 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *src, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	i;
	size_t			len;

	if (!src)
		return (0);
	len = ft_strlen(src);
	i = 0;
	a = (char *)malloc(len + 1);
	if (!a)
		return (0);
	while (i < len)
	{
		a[i] = f(i, src[i]);
		i++;
	}
	a[i] = 0;
	return (a);
}
