/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 22:42:25 by marvin            #+#    #+#             */
/*   Updated: 2021/06/03 17:30:28 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*dnext;

	*lst = ft_lstfirst(*lst);
	while (*lst)
	{
		dnext = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = dnext;
	}
}
