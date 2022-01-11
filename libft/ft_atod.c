/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:57:07 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/11 14:29:06 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *np)
{
	double	d;
	double	div;
	size_t	i;
	int		negative;

	i = 0;
	negative = 0;
	while (np[i] && (np[i] == ' ' || (np[i] < 14 && np[i] > 8) || np[i] == '+'))
		i++;
	if (np[i] == '-')
		negative = ++i;
	while (np[i] < 58 && np[i] > 47)
		d = d * 10 + (np[i++] - 48);
	if (np[i++] == '.')
	{
		div = 10.0;
		while (np[i] < 58 && np[i] > 47)
		{
			d = (d * div + (np[i++] - 48)) / div;
			div *= 10;
		}
	}
	if (negative != 0)
		return (-d);
	return (d);
}
