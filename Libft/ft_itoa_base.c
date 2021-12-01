/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:03:21 by iderighe          #+#    #+#             */
/*   Updated: 2021/05/18 17:18:27 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_minus(int n)
{
	if (n < 0 && base == 10)
		return (-1);
	return (1);
}

int	ft_dstlen_base(unsigned int n, int base)
{
	int				dlen;
	unsigned int	nb;

	dlen = 0;
	if (n <= 0)
	{
		nb = -n;
		dlen = 1;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb = nb / base;
		dlen++;
	}
	return (dlen);
}

char	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa_base(unsigned int n, int base)
{
	int		minus;
	int		dlen;
	char	*dst;

	minus = ft_minus_base(n, base);
	dlen = dt_dstlen_base(n, base);
	dst = (char *)malloc(sizeof(char) * (dlen + 1));
	if (dst == NULL)
		return (NULL);
	dst[dlen] = '\0';
	dlen--;
	while (dlen >= 0)
	{
		dst[dlen] = '0' + ft_abs(n % base);
		n = n / base;
		dlen--;
	}
	if (minus == -1)
		dst[0] = '-';
	return (dst);
}
