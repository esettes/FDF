/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bresen_settings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:53:31 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/18 00:57:25 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_bresen_step_increment(int addit_steps, t_vec2 *step, t_iter max)
{
	step->x /= max.i + addit_steps;
	step->y /= max.i + addit_steps;
}

void	set_perspective(t_fdf *fdf, t_bresen *point, t_vec2 *end)
{
	if (fdf->control.perspective == ISOMETRIC)
		isometric(fdf, &point->start, end, point->depth);
}

void	set_bresen_depth(t_fdf *fdf, t_bresen *point, t_vec2 end)
{
	t_vec2	start;

	start.x = point->start.x;
	start.y = point->start.y;
	point->depth.z = (fdf->map.map[(int)start.y][(int)start.x]
		* fdf->control.height) * fdf->control.color_height;
	point->depth.z1 = (fdf->map.map[(int)end.y][(int)end.x]
		* fdf->control.height) * fdf->control.color_height;
}

void	set_bresen_step(t_bresen *point, t_vec2 end)
{
	point->step.x = (end.x - point->start.x);
	point->step.y = (end.y - point->start.y);
}

t_vec2	set_bresen_offset(t_fdf *fdf)
{
	t_vec2	iso_offset;
	t_vec2	off;
	int		top_offset;

	iso_offset.y = 3.5;
	iso_offset.x = 9;
	top_offset = 2;
	off.x = 0;
	off.y = 0;
	if (fdf->control.perspective == ISOMETRIC)
	{
		off.x = IMG_CENTER_X - (fdf->map.px_size.x / (iso_offset.x * 6));
		off.y = IMG_CENTER_Y - (fdf->map.px_size.y / (iso_offset.y * 6));
		fdf->map.offset.x = iso_offset.x;
		fdf->map.offset.y = iso_offset.y;
	}
	else if (fdf->control.perspective == TOP_VIEW)
	{
		off.x = IMG_CENTER_X - (fdf->map.px_size.x / (top_offset * 4));
		off.y = IMG_CENTER_Y - (fdf->map.px_size.y / (top_offset * 6));
		fdf->map.offset.x = top_offset;
		fdf->map.offset.y = top_offset;
	}
	return (off);
}
