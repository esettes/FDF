/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:37:42 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/16 21:10:00 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_info(t_vec2 vertices)
{
	char	*x;
	char	*y;

	x = ft_itoa(vertices.x);
	y = ft_itoa(vertices.y);
	ft_putendl_fd(BLUE_, "Map x size:", 1);
	ft_putendl_fd(BLUE_, x, 1);
	ft_putendl_fd(BLUE_, "Map y size:", 1);
	ft_putendl_fd(BLUE_, y, 1);
	ft_putendl_fd(VIOLET_, "\nReading map...", 1);
	free(x);
	free(y);
}

/**
 * Allocs memory for `m->map`and for `m->colors`. And
 * sets the number of vertices of matrix.
 * 
 * @param m map structure
 * @param x size
 * @param y size
 */
void	set_initial_sizes(t_map *m, int x, int y)
{
	m->map = malloc(sizeof(int *) * (m->vertices.x * m->vertices.y));
	m->colors = malloc(sizeof(int *) * (m->vertices.x * m->vertices.y));
	m->vertices = set_mtrx_size(x, y);
}

int	ft_count(char const *s, char c)
{
	int		cnt;
	size_t	bo;
	char	*a;

	cnt = 0;
	bo = 0;
	if (!s)
		return (0);
	a = (char *)s;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && bo == 0)
		{
			cnt++;
			bo = 1;
		}
		if (*s == c)
			bo = 0;
		s++;
	}
	return (cnt);
}

int	*str_to_int(char *str)
{
	char	**ch_aux;
	t_iter	iter;
	int		*int_mtrx;

	iter.j = 0;
	ch_aux = ft_split(str, ' ');
	while (ch_aux[iter.j])
		iter.j++;
	int_mtrx = malloc(sizeof(int) * iter.j);
	iter.j = 0;
	while (ch_aux[iter.j])
	{
		iter.i = ft_atoi(ch_aux[iter.j]);
		*(int_mtrx + iter.j) = iter.i;
		iter.j++;
	}
	free (str);
	free(ch_aux);
	return (int_mtrx);
}
