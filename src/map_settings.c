/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:21:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/16 21:02:16 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

t_vec2	set_mtrx_size(int x, int y)
{
	t_vec2	vertices;

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
}
