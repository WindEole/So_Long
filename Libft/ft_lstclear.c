/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:17:45 by iderighe          #+#    #+#             */
/*   Updated: 2021/01/15 18:30:06 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*entry;

	entry = *lst;
	while (entry)
	{
		temp = entry->next;
		if (del)
			del(entry->content);
		free(entry);
		entry = temp;
	}
	*lst = NULL;
}
