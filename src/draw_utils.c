/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:37:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/12 19:58:52 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresen_zoom(t_fdf *fdf, t_vec2 *start, t_vec2 *end)
{
	start->x *= fdf->control.zoom;
	start->y *= fdf->control.zoom;
	end->x *= fdf->control.zoom;
	end->y *= fdf->control.zoom;
}

void	bresen_height(t_fdf *fdf, t_vec2 *start, t_vec2 *end)
{
	start->x *= fdf->control.height;
	start->y *= fdf->control.height;
	end->x *= fdf->control.height;
	end->y *= fdf->control.height;
}

float	f_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	f_abs(float a)
{
	if (a < 0)
		return (a * -1);
	else
		return (a);
}

void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth)//, t_vec2 *end, t_depth dep)
{
	float	z_zoom;
	
	z_zoom = 0.5;
	if (z_zoom >= 0 && z_zoom <= 50)
		start->x = (start->x - start->y) * cos(45) * 1;
		start->y = (start->x + start->y) * (sin(45) * z_zoom) - (depth.z *  z_zoom * (fdf->control.zoom * 0.2));
		end->x = (end->x - end->y) * cos(45) * 1;
		end->y = (end->x + end->y) * (sin(45) * z_zoom) - (depth.z1 *  z_zoom * (fdf->control.zoom * 0.2));
	(void)fdf;
}

int	check_image_limits(t_vec2 start, t_vec2 end, t_vec2 offset)
{
	if ((end.x + offset.x < (WIDTH * IMG_AUMENT) - 100) && (end.y + offset.y < (HEIGHT * IMG_AUMENT) - 100) && (end.x + offset.x > 100) 
		&& (end.y + offset.y > 100) && (start.x + offset.x < (WIDTH * IMG_AUMENT) - 100) && (start.y + offset.y < (HEIGHT * IMG_AUMENT) - 100) 
		&& (start.x + offset.x > 10) && (start.y + offset.y > 10))if ((end.x + offset.x < (WIDTH * IMG_AUMENT) - 100) && (end.y + offset.y < (HEIGHT * IMG_AUMENT) - 100) && (end.x + offset.x > 100) 
		&& (end.y + offset.y > 100) && (start.x + offset.x < (WIDTH * IMG_AUMENT) - 100) && (start.y + offset.y < (HEIGHT * IMG_AUMENT) - 100) 
		&& (start.x + offset.x > 10) && (start.y + offset.y > 10))
	{
		return TRUE;
	}
	return FALSE;
}
