/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:52:22 by marvin            #+#    #+#             */
/*   Updated: 2022/01/10 18:14:11 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t	i;
	char	*ptr;
	size_t	len;

	i = 0;
	ptr = 0;
	len = ft_strlen(src) + 1;
	while (i < len)
	{
		if (src[i] == c)
			ptr = (char *)&src[i];
		i++;
	}
	return (ptr);
}
