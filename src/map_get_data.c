/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:53:42 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/16 18:30:15 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include "colors.h"
#include "read_file.h"
#include <stdio.h>

static void	print_info(int pos);

int	obtain_z_and_color(t_map *m, char **str, int pos)
{
	char	**ch_aux;
	char	*extract;
	int		*int_mtrx;
	t_iter	iter;
	int		*int_color;

	while (str[pos])
	{
		ch_aux = ft_split(str[pos], ' ');
		int_mtrx = malloc(sizeof(int) * m->vertices.x);
		int_color = malloc(sizeof(int) * m->vertices.x);
		iter.j = -1;
		while (ch_aux[++iter.j])
		{
			get_color_and_integer(&extract, ch_aux, &iter, int_mtrx);
			set_color_for_item(extract, int_color, iter);
		}
		print_info(pos);
		m->colors[pos] = int_color;
		m->map[pos] = int_mtrx;
		free_strings(ch_aux, str[pos]);
		pos++;
	}
	set_default_color(m);
	return (EXIT_SUCCESS);
}

static void	print_info(int pos)
{
	if (pos % 50 == 0)
		ft_putendl_fd(VIOLET_, "+50 lines processed...", 1);
}

static void	get_line_default(t_map *m, int *arr, int pos)
{
	int		i_color;
	int		i;
	int		*def_color;
	char	*str;

	i = 0;
	def_color = malloc(sizeof(int) * m->vertices.x);
	i = 0;
	while (i < m->vertices.x)
	{
		i_color = arr[i];
		def_color[i] = i_color;
		i++;
	}
	m->default_colors[pos] = def_color;
	str = ft_itoa(*(m->default_colors[pos]));
	free(str);
}

void	set_default_color(t_map *m)
{
	int	i;

	i = 0;
	m->default_colors = malloc(sizeof(int *) * m->vertices.x);
	while (i < m->vertices.y)
	{
		get_line_default(m, m->colors[i], i);
		i++;
	}
}
