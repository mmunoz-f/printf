/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:42:26 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/11 19:44:18 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putstr_fd(char *src, int fd)
{
	size_t	i;

	if (!src)
		return (0);
	i = 0;
	while (src[i])
	{
		write(fd, &src[i], 1);
		i++;
	}
	return (i);
}
