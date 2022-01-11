/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:00:58 by mmunoz-f          #+#    #+#             */
/*   Updated: 2022/01/11 16:27:54 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	destroy(char **s)
{
	if (s)
	{
		if (*s)
		{
			free(*s);
			*s = 0;
		}
	}
	return (-1);
}

/*
	this is a simplified version of the get_next_line project,
	it is not really efficient cause it reads from the fd character 
	by character, in order to improve this its better to have a greater
	buffer according to a regular line size, see get_next_line project 
	in my github 
*/

int	ft_get_next_line(int fd, char **line)
{
	char	buff[2];
	int		rvalue;
	char	*temp;

	if (!line)
		return (-1);
	*line = ft_strdup("");
	if (!(*line))
		return (-1);
	rvalue = read(fd, buff, 1);
	buff[1] = 0;
	if (rvalue == 0)
		return (0);
	while (rvalue == 1 && buff[0] != '\n')
	{
		temp = *line;
		*line = ft_strjoin(*line, buff);
		if (!(*line))
			return (destroy(&temp));
		free(temp);
		rvalue = read(fd, buff, 1);
	}
	if (rvalue == -1)
		return (-1);
	return (1);
}
