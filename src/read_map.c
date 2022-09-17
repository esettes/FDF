/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/08 18:48:04 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_fd_end(char *s);

t_iter	get_map_size(int fd)
{
	t_iter	iter;
	char	**lines;
	int		aux;
	int		trigger = TRUE;

	aux = 0;
	iter.i = 0;
	iter.j = 0;
	while (get_next_line(fd) > 0)
	{
		lines[iter.i] = get_next_line(fd);
		iter.j += ft_count(lines[iter.i], ' ');
		if (trigger == TRUE)
		{
			trigger = FALSE;
			aux = iter.j;
		}
		if (check_fd_end(lines[iter.i]))
			break ;
		free(lines[iter.i]);
		iter.i++;
	}
	iter.j = aux;
	return (iter);
}

void	obtain_split_fd(int fd, t_map *m)
{
	char	**split_fd;
	t_iter	iter;
	int		aux;
	int		trigger = TRUE;
	t_iter	size_map;

	// size_map = get_map_size(fd);
	// printf("map size x: %i\n", size_map.j);
	// printf("map size y: %i\n", size_map.i);
	split_fd = malloc(sizeof(char *) * BUFFER_SIZE * 2);
	iter.i = 0;
	iter.j = 0;
	while (true)
	{
		split_fd[iter.i] = get_next_line(fd);	// i = y
		iter.j += ft_count(split_fd[iter.i], ' ');
		if (trigger == TRUE)
		{
			aux = iter.j;
			trigger = FALSE;
		}
		if (check_fd_end(split_fd[iter.i]))
			break ;
		iter.i++;
	}
	m->vertices = set_mtrx_size(aux, iter.i);
	m->map = malloc(sizeof(int *) * iter.j);
	m->colors = malloc(sizeof(int *) * iter.j);
	printf("\nm->size->y: %f \n", m->vertices.y);
	printf("m->size->x: %f \n\n", m->vertices.x);
	iter.i = 0;

	while (split_fd[iter.i])
	{
		if (iter.i % 20 == 0)
			printf("\e[2;35mloading...\e[0m\n");
		obtain_z_and_color(m, split_fd[iter.i], iter.i);
		//get_z_points(m, split_fd[iter.i], iter.i);
		//get_color_points(m, split_fd[iter.i], iter.i);
		iter.i++;
	}
}

int	ft_count(char const *s, char c)
{
	int	cnt;
	size_t	bo;
	char	*a;

	cnt = 0;
	bo = 0;
	if (!s)
		return (0);
	a = (char *)s;
	if (!a)
		return (0);
	while (*a)
	{
		if (*a != c && bo == 0)
		{
			cnt++;
			bo = 1;
		}
		if (*a == c)
			bo = 0;
		a++;
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

int	check_fd_end(char *s)
{
	if (s == NULL || ft_strncmp(s, "\n", 1) == 0)// || 
		//ft_strncmp(s, " ", 1) == 0)
		return (TRUE);
	else
		return (FALSE);
}
