/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:27:12 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/12 20:37:52 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end, int direction);

void	print_map(t_fdf *fdf)
{
	t_vec2	coord;
	t_vec2	h_end;
	t_vec2	v_end;

	coord.y = 0;
	while (coord.y < fdf->mtrx.vertices.y)
	{
		coord.x = 0;
		while (coord.x < fdf->mtrx.vertices.x)
		{
			if (coord.x < fdf->mtrx.vertices.x - 1)
			{
				v_end.y = coord.y;
				v_end.x = coord.x + 1;
				f_bresen(fdf, coord, v_end, 0);
			}
			if (coord.y < fdf->mtrx.vertices.y - 1)
			{
				h_end.x = coord.x;
				h_end.y = coord.y + 1;
				f_bresen(fdf, coord, h_end, 1);
			}
			coord.x++;
		}
		coord.y++;
	}
}

void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end, int direction)
{
	t_vec2	step;
	int		max;
	int		p;
	t_vec2	offset;
	t_depth	depth;
	t_iter	curr;

	curr.i = (int)start.x;
	curr.j = (int)start.y;
	depth.z = fdf->mtrx.mtrx[(int)start.y][(int)start.x] * fdf->control.height;
	depth.z1 = fdf->mtrx.mtrx[(int)end.y][(int)end.x] * fdf->control.height;
	bresen_zoom(fdf, &start, &end);
	offset.x = IMG_CENTER_X - (fdf->mtrx.px_size.x / 2);
	offset.y = IMG_CENTER_Y - (fdf->mtrx.px_size.y / 2);
	if (fdf->control.perspective == ISOMETRIC)
	{
		offset.x = IMG_CENTER_X - (fdf->mtrx.px_size.x / 9);
		offset.y = IMG_CENTER_Y - (fdf->mtrx.px_size.y / 3.5);
		isometric(fdf, &start, &end, depth);
	}
	start.x += fdf->control.horiz;
	start.y += fdf->control.vert;
	end.x += fdf->control.horiz;
	end.y += fdf->control.vert;

	step.x = (end.x - start.x);
	step.y = (end.y - start.y);
	max = f_max(f_abs(step.x), f_abs(step.y));
	step.x /= max + 3;
	step.y /= max + 3;

	int i = 0;
	while (i <= max + 3)
	{
		if (check_image_limits(start, end, offset))
			mlx_put_pixel(fdf->img, start.x + offset.x , start.y + offset.y, fdf->mtrx.colors[curr.j][curr.i]);
		start.x += step.x;
		start.y += step.y;
		i ++;
	}
}

