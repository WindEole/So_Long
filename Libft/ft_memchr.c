/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:02:59 by iderighe          #+#    #+#             */
/*   Updated: 2021/01/20 11:17:41 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*index;

	index = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*index == (unsigned char)c)
			return (index);
		index++;
		i++;
	}
	return (NULL);
}
