/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 21:37:42 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/15 23:34:58 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_info(t_vec2 vertices)
{
	printf("Map x size: %f \n", vertices.x);
	printf("Map y size: %f \n\n", vertices.y);
	printf("\e[1;35mReading map...\e[0m\n");
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

// int	process_map(char **str, t_map *m)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (i % 50 == 0)
// 			printf("\e[2;35m%i lines processed...\e[0m\n", i);
// 		if(obtain_z_and_color(m, str[i], i) == EXIT_FAILURE)//, get_line_size(split_fd[iter.i]));
// 			return (EXIT_FAILURE);
// 		i++;
// 	}
// 	free(str);
// 	set_default_color(m);
// 	return (EXIT_SUCCESS);
// }