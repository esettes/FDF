/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 00:51:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/15 22:41:12 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fdf.h"
#include "gnl.h"
# include "structs.h"
# include "macros.h"
# include "map_utils.h"
# include "colors.h"
# include "libft.h"
# include "map_utils.h"
# include "read_file.h"

int	check_fd_end(char *s);
void	set_z_points(t_fdf *fdf, char *raw_map);
int	ft_count(char const *s, char c);

/* Check map validity after get all lines of fd
 if (check_valid_map(split_fd, m->vertices) == EXIT_FAILURE)
 	return (EXIT_FAILURE);*/
int	obtain_split_fd(int fd, t_map *m)
{
	char	**split_fd;
	t_iter	iter;
	int		aux;
	int		trigger = TRUE;

	split_fd = malloc(sizeof(char *) * BUFFER_SIZE * 2);
	iter.i = 0;
	iter.j = 0;
	while (true)
	{
		split_fd[iter.i] = get_next_line(fd);	// i = y
		if (split_fd[iter.i] == NULL)
			break ;
		iter.j += ft_count(split_fd[iter.i], ' ');
		if (trigger == TRUE)
		{
			aux = iter.j;
			trigger = FALSE;
		}
		iter.i++;
	}
	m->vertices = set_mtrx_size(aux, iter.i);
	// Check map validity
	// if (check_valid_map(split_fd, m->vertices) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	m->map = malloc(sizeof(int *) * (m->vertices.x * m->vertices.y));
	m->colors = malloc(sizeof(int *) * (m->vertices.x * m->vertices.y));
	print_info(m->vertices);
	iter.i = 0;
	// while (split_fd[iter.i])
	// {
	// 	if (iter.i % 50 == 0)
	// 		printf("\e[2;35m%i lines processed...\e[0m\n", iter.i);
	// 	if(obtain_z_and_color(m, split_fd[iter.i], iter.i) == EXIT_FAILURE)//, get_line_size(split_fd[iter.i]));
	// 		return (EXIT_FAILURE);
	// 	iter.i++;
	// }
	if (obtain_z_and_color(m, split_fd, iter.i) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(split_fd);
	set_default_color(m);
	return (EXIT_SUCCESS);
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
			
			if (!(ft_strncmp(aux, " ", 1) == 0 || ft_strncmp(aux, "\n", 1) == 0 || ft_strncmp(aux, "\n", 1) == 0 || 
				!ft_isalnum((char)aux) || ft_strncmp(aux, "-", 1) == 0 || ft_strncmp(aux, " +", 1) == 0 || 
				ft_strncmp(aux, ",", 1) == 0))// || ft_strncmp(aux, " ", 1) (char)0)
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
