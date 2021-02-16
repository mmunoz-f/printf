/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:13:30 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/02/16 18:25:34 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_addchr(char **s, char c)
{
	char	new[2];
	char	*temp;

	new[0] = c;
	new[1] = 0;
	temp = *s;
	if (!(*s = ft_strjoin(*s, new)))
		return (0);
	free(temp);
	return (1);
}
