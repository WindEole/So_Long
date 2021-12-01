/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:10:08 by iderighe          #+#    #+#             */
/*   Updated: 2021/01/06 15:10:39 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*index;

	index = (char *)s;
	while (*index != '\0')
	{
		if (*index == c)
			return (index);
		index++;
	}
	if (*index == '\0' && c == '\0')
		return (index);
	return (NULL);
}
