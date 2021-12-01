/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:10:51 by iderighe          #+#    #+#             */
/*   Updated: 2021/01/20 10:42:29 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;

	x = ft_strlen(src);
	y = ft_strlen(dest);
	if (dstsize <= y)
		return (dstsize + x);
	if (dstsize == 0)
		return (0);
	i = 0;
	while (dest[i] != '\0' && i < dstsize)
		i++;
	j = i;
	while (src[i - j] != '\0' && (i < (dstsize - 1)))
	{
		dest[i] = src[i - j];
		i++;
	}
	if (i < dstsize)
		dest[i] = '\0';
	return (x + y);
}
