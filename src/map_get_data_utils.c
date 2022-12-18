/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_data_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:38:19 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/18 01:07:09 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "colors.h"
#include "libft.h"
#include <stddef.h>

void	get_color_and_integer(char **extr, char **ch, t_iter *iter, int *mtrx)
{
	*extr = ft_strchr(ch[iter->j], 'x');
	iter->i = ft_atoi(ch[iter->j]);
	iter->i *= 0.8;
	mtrx[iter->j] = iter->i;
}

void	set_color_to_arr(char *extract, int i, int *arr)
{
	int	color;

	extract++;
	color = hex_to_color(extract);
	*(arr + i) = color;
	extract = "";
}

void	set_color_for_item(char *extract, int *arr_color, t_iter iter)
{
	if (extract)
		set_color_to_arr(extract, iter.j, arr_color);
	else
		set_color_palet(arr_color, get_color_palette(1), iter.j, iter.i);
}

void	process_item(char **extr, char **ch, t_iter *i, int *mtrx, int *color)
{
	get_color_and_integer(extr, ch, i, mtrx);
	set_color_for_item(*extr, color, *i);
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
