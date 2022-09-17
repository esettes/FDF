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

void	set_control_zoom(t_fdf *fdf, t_vec2 *start, t_vec2 *end)
{
	start->x *= fdf->control.zoom;// * cos(fdf->control.rot_angle  * 3.141592653589 / 180);
	start->y *= fdf->control.zoom;// * cos(fdf->control.rot_angle);
	end->x *= fdf->control.zoom;// * cos(fdf->control.rot_angle  * 3.141592653589 / 180);
	end->y *= fdf->control.zoom;// * cos(fdf->control.rot_angle);
}

void	set_control_movement(t_fdf *fdf, t_vec2 *start, t_vec2 *end)
{
	start->x += fdf->control.horiz;
	start->y += fdf->control.vert;
	end->x += fdf->control.horiz;
	end->y += fdf->control.vert;
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

int	check_image_limits(t_vec2 start, t_vec2 end, t_vec2 off)
{
	float	max_w;
	float	max_h;
	int		min;

	max_w = WIDTH * IMG_AUMENT - 100;
	max_h = HEIGHT * IMG_AUMENT - 100;
	min = 100;
	if ((end.x + off.x < max_w) && (end.y + off.y < max_h) 
		&& (end.x + off.x > min) && (end.y + off.y > min) 
		&& (start.x + off.x < max_w) && (start.y + off.y < max_h) 
		&& (start.x + off.x > min) && (start.y + off.y > min))
	{
		return TRUE;
	}
	return FALSE;
}
