/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:32:43 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/30 15:45:55 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *s, int r)
{
	printf(RED"\n");
	ft_putstr_fd(s, 2);
	printf(RESET"\n");
	return (r);
}

t_adm	*ft_free_adm_u(t_adm *adm)
{
	t_dll	*now;

	if (!adm)
		return (NULL);
	now = adm->head;
	while (now->r != NULL)
	{
		now = now->r;
		free(now->l);
	}
	free(now);
	free(adm);
	return (NULL);
}

void	*ft_free_allist(t_adm **adm, int y, void *r)
{
	if (!adm)
		return (r);
	while (--y != -1)
		ft_free_adm_u(adm[y]);
	free(adm);
	return (r);
}

void	*ft_free_line(char *s, int ret, void *r)
{
	if (ret == -1)
		return (r);
	if (!s)
		return (r);
	free(s);
	return (r);
}
