/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:12:18 by iderighe          #+#    #+#             */
/*   Updated: 2021/11/30 17:02:56 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count_elm(t_adm **adm, t_dll *now, int y)
{
	int	v[4];

	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	v[0] = -1;
	while (++v[0] < y)
	{
		now = adm[v[0]]->head;
		while (now != NULL)
		{
			if (now->c == 'P')
				v[1]++;
			if (now->c == 'E')
				v[2]++;
			if (now->c == 'C')
				v[3]++;
			now = now->r;
		}
	}
	if (v[1] != 1 || v[2] <= 0 || v[3] <= 0)
		return (FALSE);
	return (TRUE);
}

static int	ft_valid_char(t_adm **adm, int y)
{
	t_dll	*now;
	int		v;

	v = -1;
	while (++v < y)
	{
		now = adm[v]->head;
		if (v == 0 || v == y - 1)
		{
			while (now != NULL)
			{
				if (now->c != '1')
					return (FALSE);
				now = now->r;
			}
		}
		else if (adm[v]->head->c != '1' || adm[v]->tail->c != '1')
			return (FALSE);
	}
	if (!ft_count_elm(adm, now, y))
		return (FALSE);
	return (TRUE);
}

static int	ft_count_rows(int fd, int y, int v)
{
	char	*line;
	int		ret;
	int		len;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (-1);
	len = ft_strlen(line);
	free(line);
	y++;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (-1);
		if (line[0] != '\0' && ft_strlen(line) != len)
			v++;
		if (line[0] != '\0')
			y++;
		free(line);
	}
	close(fd);
	if (v)
		return (-1);
	return (y);
}

/*static int	ft_check_end_name(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (ft_strlen(s) >= 5)
		if (s[i] == 'r' && s[--i] == 'e' && s[--i] == 'b' && s[--i] == '.')
			return (TRUE);
	return (FALSE);
}*/

static int	ft_valid_file(int ac, char *s)
{
	int	i;

	if (ac < 2)
		return (ft_error("Error\n- no argument", 0));
	if (ac > 2)
		printf(GREEN"Only the first file will be used !"RESET"\n");
	if (open(s, O_DIRECTORY) > 0)
		return (ft_error("Error\n- arg is a directory", 0));
	i = ft_strlen(s) - 1;
	if (ft_strlen(s) >= 5)
	{
		if (s[i] == 'r' && s[--i] == 'e' && s[--i] == 'b' && s[--i] == '.')
			return (TRUE);
		else
			return (ft_error("Error\n- arg is not a [.ber] file", 0));
	}
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_adm	**adm;
	int		y;

	if (!ft_valid_file(ac, av[1]))
		return (EXIT_FAILURE);
	y = ft_count_rows(open(av[1], O_RDONLY), 0, 0);
	if (y == -1)
		return (ft_error("Error\n- invalid map : not rectangular", 1));
	adm = malloc(sizeof(*adm) * y);
	adm = ft_create_map(adm, open(av[1], O_RDONLY), 0);
	if (adm == NULL)
		return (EXIT_FAILURE);
	if (!ft_valid_char(adm, y))
	{
		ft_free_allist(adm, y, NULL);
		return (ft_error("Error\n- invalid map : misconfiguration", 1));
	}
	all_display(adm, y);
	ft_free_allist(adm, y, NULL);
	return (EXIT_SUCCESS);
}
