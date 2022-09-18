/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_props.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:21:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/25 04:27:08 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	set_mtrx_size(int x, int y)
{
	t_vec2 vertices;
	
	vertices.x = x;
	vertices.y = y;
	return (vertices);
}

void	set_pixel_size(t_fdf *fdf)
{
	fdf->map.px_size.x = fdf->control.zoom * fdf->map.vertices.x;
	fdf->map.px_size.y = fdf->control.zoom * fdf->map.vertices.y;
}

void	set_new_zoom(t_fdf *fdf)
{
	fdf->map.px_size.x = fdf->control.zoom * (fdf->map.vertices.x - 1);
	fdf->map.px_size.y = fdf->control.zoom * (fdf->map.vertices.y - 1);
	//set_limits(&fdf->map);
}

// void	set_limits(t_map *map)
// {
// 	map->start.x = (IMG_CENTER_X - (map->px_size.x / 2));
// 	map->start.y = (IMG_CENTER_Y - (map->px_size.y / 2));
// 	map->end.x = map->start.x + map->px_size.x;
// 	map->end.y = map->start.y + map->px_size.y;
// }
