/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:04:40 by iderighe          #+#    #+#             */
/*   Updated: 2021/01/06 15:04:44 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*index;
	int		slen;

	index = (char *)s;
	slen = ft_strlen(index);
	while (slen >= 0)
	{
		if (index[slen] == c)
			return (&index[slen]);
		slen--;
	}
	return (NULL);
}
