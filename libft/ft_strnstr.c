/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:55:34 by marvin            #+#    #+#             */
/*   Updated: 2022/01/10 18:14:09 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	total;

	i = 0;
	if (!(ft_strlen(little)))
		return (big);
	while (big[i] && i < len)
	{
		total = 0;
		while (big[i + total] == little[total] && i + total < len)
		{
			total++;
			if (little[total] == 0)
				return (&big[i]);
		}
		i++;
	}
	return (0);
}
