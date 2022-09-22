/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:53:42 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/22 23:53:43 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_line_default(t_map *m, int *arr, int pos);

void    get_z_points(t_map *m, char *str, int pos)
{
    char	**ch_aux;
    int		*z_point;
    t_iter  iter;
    t_iter  aux;

    iter.i = 0;
    iter.j = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    z_point = malloc(sizeof(int) * iter.j + 1);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        iter.i = ft_atoi(ch_aux[iter.j]);
		*(z_point + iter.j) = iter.i;
		iter.j++;
    }
    m->map[pos] = z_point;
    if (ch_aux)
        free (ch_aux);
    free (str);
}

void	get_color_points(t_map *m, char *str, int pos)
{
    char	**ch_aux;
    char    *extract;
    int     i_color;
    t_iter  iter;
    int     *int_color;

    iter.i = 0;
    iter.j = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    int_color = malloc(sizeof(int) * iter.j + 1);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        extract = ft_strchr(ch_aux[iter.j], 'x');
        if (extract)
        {
            extract++;
            i_color = str_to_color(extract);
            *(int_color + iter.j) = i_color;
            extract = ""; 
        }
        else
          *(int_color + iter.j) = 255;
		iter.j++;
    }
    m->colors[pos] = int_color;
    if (ch_aux)
        free (ch_aux);
    free (str);
}

int    get_line_size(char *str)
{
    char	**ch_aux;
    int     i;

    i = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[i])
        i++;
    free (ch_aux);
    return (i);
}

int	obtain_z_and_color(t_map *m, char *str, int pos)//, int size)
{
    char	**ch_aux;
    char    *extract;
    int     i_color;
    //int		int_mtrx[size];
    int		*int_mtrx;
    t_iter  iter;
    //int     int_color[size];
    int     *int_color;

    iter.i = 0;
    iter.j = 0;
    //count_line_elements(str, &aux.j);
    ch_aux = ft_split(str, ' ');
    int_mtrx = malloc(sizeof(int) * m->vertices.x);
    int_color = malloc(sizeof(int) * m->vertices.x);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        extract = ft_strchr(ch_aux[iter.j], 'x');
        iter.i = ft_atoi(ch_aux[iter.j]);
        int_mtrx[iter.j] = iter.i;
        if (extract)
        {
            extract++;
            i_color = str_to_color(extract);
            int_color[iter.j] = i_color;
            extract = ""; 
        }
        else// if (!extract)
        {
            //int_color[iter.j] = 0;
            set_color_palette(int_color, get_color_palette(1), iter.j, iter.i);
        }
		iter.j++;
    }
    iter.i = 0;
    m->colors[pos] = int_color;
    m->map[pos] = int_mtrx;
    //free (int_mtrx);
    while (ch_aux[iter.i])
    {
        free(ch_aux[iter.i]);
        iter.i++;
    }
    free(ch_aux);
    free(str);
    return (EXIT_SUCCESS);
}
// void	save_default_color(t_map *m)
// {
//     int     i_color;
//     t_iter  it;
//     int    **def_color;
//     int     size;

//     it.i = 0;
//     size = 0;
//     m->default_colors = malloc(sizeof(int *) * m->vertices.y);
// 	while (m->colors[it.i])
//     {
//         it.j = 0;
//         size = 0;
//         while (m->colors[it.i][size])
// 		    size++;
//         def_color[it.i] = malloc(sizeof(int) * size);
//         while (m->colors[it.i][it.j])
//         {
//             i_color = m->colors[it.i][it.j];
//             def_color[it.i][it.j] = i_color;
//             it.j++;
//         }
//         m->default_colors[it.i] = def_color[it.i];
// 		it.i++;
//     }
   
// }
void    set_default_color(t_map *m)
{
    int i;

    i = 0;
    m->default_colors = malloc(sizeof(int *) * m->vertices.x);
    while (i < m->vertices.y)
    {
        get_line_default(m, m->colors[i], i);
        i++;
    }
}

static void	get_line_default(t_map *m, int *arr, int pos)
{
    int     i_color;
    int     i;
    int     *def_color;

    i = 0;
    // while (arr[i])
	// 	i++;
    def_color = malloc(sizeof(int) * m->vertices.x); //i;
    i = 0;
	while (i < m->vertices.x)//(arr[i])
    {
        i_color = arr[i];
        def_color[i] = i_color;
		i++;
    }
    m->default_colors[pos] = def_color;
}
