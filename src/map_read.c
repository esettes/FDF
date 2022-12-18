/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/19 00:29:40 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "structs.h"
#include "macros.h"
#include "map_utils.h"
#include "colors.h"
#include "libft.h"
#include "map_utils.h"
#include "read_file.h"
#include <stdio.h>

static void		init_split_fd_values(t_iter *iter, int *trigger);
static int		allocate_map_arrays(t_map *m, char **str, int pos);
static void		save_x_value(int *aux, int *j, int *trigger);

int	obtain_split_fd(int fd, t_map *m)
{
	char	**split_fd;
	t_iter	iter;
	int		aux;
	int		trigger;

	split_fd = malloc(sizeof(char *) * BUFFER_SIZE * 2);
	init_split_fd_values(&iter, &trigger);
	while (++iter.i + 2)
	{
		split_fd[iter.i] = get_next_line(fd);
		if (split_fd[iter.i] == NULL)
			break ;
		if (check_map_size(split_fd, iter.i) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		iter.j += ft_count(split_fd[iter.i], ' ');
		if (trigger == TRUE)
			save_x_value(&aux, &iter.j, &trigger);
	}
	m->vertices = set_mtrx_size(aux, iter.i);
	if (check_valid_map(split_fd, m->vertices) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (allocate_map_arrays(m, split_fd, iter.i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(split_fd);
	return (EXIT_SUCCESS);
}

void	free_bronken_map(char **str, int len)
{
	while (len >= 0)
	{
		free(str[len]);
		len--;
	}
	free(str);
}

static void	save_x_value(int *aux, int *j, int *trigger)
{
	*aux = *j;
	*trigger = FALSE;
}

static int	allocate_map_arrays(t_map *m, char **str, int pos)
{
	m->map = malloc(sizeof(int *) * (m->vertices.x * m->vertices.y));
	m->colors = malloc(sizeof(int *) * (m->vertices.x * m->vertices.y));
	print_info(m->vertices);
	if (obtain_z_and_color(m, str, pos) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	init_split_fd_values(t_iter *iter, int *trigger)
{
	iter->i = -1;
	iter->j = 0;
	*trigger = TRUE;
}
