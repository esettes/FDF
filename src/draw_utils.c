/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:37:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/11/24 01:23:56 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_draw_control_zoom(t_fdf *fdf, t_vec2 *start, t_vec2 *end)
{
	start->x *= fdf->control.zoom;// * cos(fdf->control.rot_angle * 3.14 / 180);
	start->y *= fdf->control.zoom;// * cos(fdf->control.rot_angle);
	end->x *= fdf->control.zoom;// * cos(fdf->control.rot_angle  * 3.14 / 180);
	end->y *= fdf->control.zoom;// * cos(fdf->control.rot_angle);
}

void	set_draw_control_movement(t_fdf *fdf, t_vec2 *start, t_vec2 *end)
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

int	check_image_limits(t_bresen *point, t_vec2 end)
{
	int		min;
	t_vec2	offset;
	t_vec2	start;

	min = 100;
	offset.x = point->offset.x;
	offset.y = point->offset.y;
	start.x = point->start.x;
	start.y = point->start.y;
	if ((end.x + offset.x < MAX_WIDTH) && (end.y + offset.y < MAX_HEIGHT)
		&& (end.x + offset.x > min) && (end.y + offset.y > min)
		&& (start.x + offset.x < MAX_WIDTH) && (start.y + offset.y < MAX_HEIGHT)
		&& (start.x + offset.x > min) && (start.y + offset.y > min))
	{
		return (TRUE);
	}
	return (FALSE);
}
