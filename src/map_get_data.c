/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:53:42 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/16 00:01:07 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "structs.h"
#include "colors.h"
#include <stdio.h>

void	set_color_to_arr(char *extract, int i, int *arr);
void	set_color_for_item(char *extract, int *arr_color, t_iter iter);
void	get_color_and_integer(char **extr, char **ch, t_iter *iter, int *mtrx);
void	free_strings(char **ch_aux, char *str);

int	get_line_size(char *str)
{
	char	**ch_aux;
	int		i;

	i = 0;
	ch_aux = ft_split(str, ' ');
	while (ch_aux[i])
		i++;
	free (ch_aux);
	return (i);
}

int	obtain_z_and_color(t_map *m, char **str, int pos)
{
	char	**ch_aux;
	char	*extract;
	int		*int_mtrx;
	t_iter	iter;
	int		*int_color;

	while (str[pos++])
	{
		ch_aux = ft_split(str[pos], ' ');
		int_mtrx = malloc(sizeof(int) * m->vertices.x);
		int_color = malloc(sizeof(int) * m->vertices.x);
		iter.j = 0;
		while (ch_aux[iter.j])
		{
			get_color_and_integer(&extract, ch_aux, &iter, int_mtrx);
			set_color_for_item(extract, int_color, iter);
			iter.j++;
		}
		if (pos % 50 == 0)
			printf("\e[2;35m%i lines processed...\e[0m\n", pos);
		m->colors[pos] = int_color;
		m->map[pos] = int_mtrx;
		free_strings(ch_aux, str[pos]);
	}
	return (EXIT_SUCCESS);
}

void	get_color_and_integer(char **extr, char **ch, t_iter *iter, int *mtrx)
{
	*extr = ft_strchr(ch[iter->j], 'x');
	iter->i = ft_atoi(ch[iter->j]);
	mtrx[iter->j] = iter->i;
}

void	set_color_for_item(char *extract, int *arr_color, t_iter iter)
{
	if (extract)
		set_color_to_arr(extract, iter.j, arr_color);
	else
		set_color_palette(arr_color, get_color_palette(1), iter.j, iter.i);
}

void	set_color_to_arr(char *extract, int i, int *arr)
{
	int	color;

	extract++;
	color = str_to_color(extract);
	*(arr + i) = color;
	extract = "";
}

void	free_strings(char **ch_aux, char *str)
{
	int	i;

	i = 0;
	while (ch_aux[i])
	{
		free(ch_aux[i]);
		i++;
	}
	free(ch_aux);
	free(str);
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
