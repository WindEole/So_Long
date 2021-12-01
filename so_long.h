/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 12:12:58 by iderighe          #+#    #+#             */
/*   Updated: 2021/12/01 17:49:40 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "Libft/libft.h"
//# include "mlx.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
# define TRUE 1
# define FALSE 0

# define BUFFER_SIZE 8

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"

typedef struct s_adm
{
	struct s_dll	*head;
	struct s_dll	*tail;
}	t_adm;

typedef struct s_dll
{
	char			c;
	int				x;
	int				y;
	struct s_dll	*r;
	struct s_dll	*l;
}	t_dll;

typedef struct s_elm
{
	int	p;
	int	c;
	int	e;
}	t_elm;

// create_lst_map.c

t_adm	**ft_create_map(t_adm **adm, int fd, int y);

// all_display.c

void	all_display(t_adm **adm, int y);

// error_free

int		ft_error(char *s, int ret);
void	*ft_free_line(char *s, int ret, void *r);
void	*ft_free_allist(t_adm **adm, int y, void *r);
t_adm	*ft_free_adm_u(t_adm *adm);

// libft

//int		ft_strlen(char *str);
//void	ft_putstr_fd(char *s, int fd);

// get_next_line

int		get_next_line(int fd, char **line);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strn(char *s);

#endif
