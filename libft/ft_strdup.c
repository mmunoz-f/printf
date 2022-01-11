/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 11:00:18 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/10 18:20:39 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*result;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	result = malloc(len + 1);
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = src[i];
		i++;
	}
	result[i] = 0;
	return (result);
}
