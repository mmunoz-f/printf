/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 12:10:46 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/10 14:23:12 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *src, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*a;

	if (!src)
		return (0);
	start = 0;
	while (src[start] && ft_strchr(set, src[start]))
		start++;
	end = ft_strlen(src) - 1;
	while (end > start && ft_strchr(set, src[end]))
		end--;
	a = (char *)malloc(end - start + 2);
	if (!a)
		return (0);
	i = 0;
	while (start + i <= end)
	{
		a[i] = src[start + i];
		i++;
	}
	a[i] = 0;
	return (a);
}
