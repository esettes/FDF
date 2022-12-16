/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/16 21:12:00 by iostancu         ###   ########.fr       */
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

static void	init_split_fd_values(t_iter *iter, int *trigger);
static void	allocate_map_arrays(t_map *m);
static void	save_x_value(int *aux, int *j, int *trigger);

int	obtain_split_fd(int fd, t_map *m)
{
	char	**split_fd;
	t_iter	iter;
	int		aux;
	int		trigger;

	split_fd = malloc(sizeof(char *) * BUFFER_SIZE * 2);
	init_split_fd_values(&iter, &trigger);
	while (true)
	{
		split_fd[iter.i] = get_next_line(fd);
		if (split_fd[iter.i] == NULL)
			break ;
		iter.j += ft_count(split_fd[iter.i], ' ');
		if (trigger == TRUE)
			save_x_value(&aux, &iter.j, &trigger);
		iter.i++;
	}
	m->vertices = set_mtrx_size(aux, iter.i);
	// Check map validity
	// if (check_valid_map(split_fd, m->vertices) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	allocate_map_arrays(m);
	iter.i = 0;
	if (obtain_z_and_color(m, split_fd, iter.i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(split_fd);
	return (EXIT_SUCCESS);
}

static void	save_x_value(int *aux, int *j, int *trigger)
{
	*aux = *j;
	*trigger = FALSE;
}

static void	allocate_map_arrays(t_map *m)
{
	m->map = malloc(sizeof(int *) * (m->vertices.x * m->vertices.y));
	m->colors = malloc(sizeof(int *) * (m->vertices.x * m->vertices.y));
	print_info(m->vertices);
}

static void	init_split_fd_values(t_iter *iter, int *trigger)
{
	iter->i = 0;
	iter->j = 0;
	*trigger = TRUE;
}

int	check_valid_map(char **map, t_vec2 size)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			aux = &(map[i][j]);
			if (!(ft_strncmp(aux, " ", 1) == 0 || ft_strncmp(aux, "\n", 1) == 0
					|| ft_strncmp(aux, "\n", 1) == 0
					|| !ft_isalnum((char)aux)
					|| ft_strncmp(aux, "-", 1) == 0
					|| ft_strncmp(aux, " +", 1) == 0
					|| ft_strncmp(aux, ",", 1) == 0))
				// || ft_strncmp(aux, " ", 1) (char)0)
			{
				ft_putendl_fd(RED_, "Error: Invalid map", 1);
				return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
