/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:23:01 by iderighe          #+#    #+#             */
/*   Updated: 2021/01/13 18:07:06 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy_trim(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	deb;
	size_t	fin;
	char	*newstr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	deb = 0;
	while (s1[deb] && ft_strchr(set, s1[deb]))
		deb++;
	fin = ft_strlen(s1 + deb);
	if (fin)
		while (s1[deb + fin - 1] != 0 && ft_strchr(set, s1[deb + fin - 1]) != 0)
			fin--;
	newstr = malloc(sizeof(char) * (fin + 1));
	if (newstr == NULL)
		return (NULL);
	ft_strncpy_trim(newstr, s1 + deb, fin);
	newstr[fin] = '\0';
	return (newstr);
}
