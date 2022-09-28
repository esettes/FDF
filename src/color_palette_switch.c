/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette_switch.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:52:54 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/22 23:52:55 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*get_color_palette(int palette)
{
	void (*ptr)(int *, int, int);

    if (palette == 0)
		ptr = &palette_default;
	if (palette == 1)
		ptr = &palette_terrain;
	if (palette == 2)
		ptr = &palette_gamma_red;
    if (palette == 3)
		ptr = &palette_gamma;
    if (palette == 4)
		ptr = &palette_test;
	return ptr;
}

void	set_color_palette(int *arr, void (*f)(int *, int, int), int pos, int z_value) //t_fdf *fdf, 
{
	f(arr, pos, z_value);
}

void    set_color_array(t_fdf *fdf)
{
    int i;
    int j;
    int *arr;
    int val;

    i = 0;
    while (i < fdf->map.vertices.y)
    {
        j = 0;
        while (j < fdf->map.vertices.x)
        {
            if (fdf->control.palette == 0)
                val = fdf->map.default_colors[i][j];
            else
                val = fdf->map.map[i][j];
            set_color_palette(fdf->map.colors[i], 
                get_color_palette(fdf->control.palette), j, val);
            j++;
        }
        i++;
    }
    //return (TRUE);
    //fdf->map.colors = arr;
}