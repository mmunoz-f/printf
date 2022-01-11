/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:37:19 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/11 16:51:12 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *src, const char *set)
{
	size_t	i;

	i = 0;
	while (src[i] && !ft_strchr(set, src[i]))
		i++;
	return (i);
}

static void	destroy(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i]);
	free(arr);
}

static int	resize(char ***arr)
{
	size_t	len;
	size_t	i;
	char	**tmp;

	len = 0;
	while ((*arr)[len])
		len++;
	tmp = *arr;
	*arr = malloc(sizeof(char *) * (len + 2));
	if (!arr)
	{
		destroy(tmp);
		return (1);
	}
	i = 0;
	while (i < len)
	{
		(*arr)[i] = tmp[i];
		i++;
	}
	(*arr)[i] = 0;
	free(tmp);
	return (0);
}

static int	add_word(char ***arr, char const *src, size_t *i, const char *set)
{
	size_t	j;
	size_t	wlen;

	if (resize(arr))
		return (1);
	j = 0;
	while ((*arr)[j])
		j++;
	wlen = word_len(&(src[*i]), set);
	(*arr)[j] = ft_substr(src, *i, wlen);
	if (!(*arr)[j])
	{
		destroy(*arr);
		return (1);
	}
	*i += wlen;
	(*arr)[j + 1] = 0;
	return (0);
}

char	**ft_split(char const *src, const char *set)
{
	char	**arr;
	size_t	i;

	if (!src || !set)
		return (0);
	arr = malloc(sizeof(char *));
	if (!arr)
		return (0);
	*arr = 0;
	i = 0;
	while (src[i])
	{
		if (!(ft_strchr(set, src[i])))
		{
			if (add_word(&arr, src, &i, set))
				return (0);
		}
		else
			i++;
	}
	return (arr);
}
