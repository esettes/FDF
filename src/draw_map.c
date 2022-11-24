/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:27:12 by iostancu          #+#    #+#             */
/*   Updated: 2022/11/24 01:21:55 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		f_bresen(t_fdf *fdf, t_bresen point, t_vec2 end);
static void	draw_right_segment(t_fdf *fdf, t_bresen point, t_vec2 *end);
static void	draw_left_segment(t_fdf *fdf, t_bresen point, t_vec2 *end);

int	print_map(t_fdf *fdf)
{
	t_bresen	*point;

	point = (t_bresen *)malloc(sizeof(t_bresen));
	point->start.y = 0;
	set_color_array(fdf);
	point->offset = set_bresen_offset(fdf);
	while (point->start.y < fdf->map.vertices.y)
	{
		point->start.x = 0;
		while (point->start.x < fdf->map.vertices.x)
		{
			get_current_position(point->start, &point->curr);
			if (point->start.x < fdf->map.vertices.x - 1)
				draw_right_segment(fdf, *point, &point->v_end);
			if (point->start.y < fdf->map.vertices.y - 1)
				draw_left_segment(fdf, *point, &point->h_end);
			point->start.x++;
		}
		point->start.y++;
	}
	free(point);
	return (EXIT_SUCCESS);
}

void	f_bresen(t_fdf *fdf, t_bresen point, t_vec2 end)
{
	t_iter	max;
	t_vec2	coord;

	set_bresen_depth(fdf, &point, end);
	set_draw_control_zoom(fdf, &point.start, &end);
	set_perspective(fdf, &point, &end);
	rotate_point(fdf, &point, &end);
	//rotate_top_on_y(fdf, &point, &end);
	//rotate_top_on_y_3d(fdf, &point, &end);
	set_draw_control_movement(fdf, &point.start, &end);
	set_bresen_step(&point, end);
	max.i = f_max(f_abs(point.step.x), f_abs(point.step.y));
	set_bresen_step_increment(fdf->control.points_resolution, &point.step, max);
	max.j = 0;
	coord.x = point.start.x + point.offset.x;
	coord.y = point.start.y + point.offset.y;
	while (max.j++ <= max.i + fdf->control.points_resolution)
	{
		if (check_image_limits(&point, end))
			mlx_put_pixel(fdf->img, coord.x, coord.y,
				fdf->map.colors[point.curr.j][point.curr.i]);
		step_increment(&coord, point.step);
	}
}

//obtain window size
// void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end, t_vec2 offset)
// {
// 	t_vec2	step;
// 	t_iter	max;
// 	t_depth	depth;
// 	t_iter	curr;

// 	get_current_position(start, &curr);
// 	set_bresen_depth(fdf, &depth, start, end);
// 	set_draw_control_zoom(fdf, &start, &end);
// 	set_perspective(fdf, &start, &end, depth);
// 	rotate_point(fdf, &start, &end, &depth);
// 	//rotate_top_on_y(fdf, &start, &end, &depth);
// 	//rotate_top_on_y_3d(fdf, &start, &end, &depth);
// 	set_draw_control_movement(fdf, &start, &end);
// 	set_bresen_step(&step, start, end);
// 	max.i = f_max(f_abs(step.x), f_abs(step.y));
// 	set_bresen_step_increment(fdf->control.points_resolution, &step, max);
// 	max.j = 0;
// 	while (max.j++ <= max.i + fdf->control.points_resolution)
// 	{
// 		if (check_image_limits(start, end, offset))
// 			mlx_put_pixel(fdf->img, start.x + offset.x , start.y + offset.y, 
// 			fdf->map.colors[curr.j][curr.i]);
// 		step_increment(&start, step);
// 	}
// }

static	void	draw_right_segment(t_fdf *fdf, t_bresen point, t_vec2 *end)
{
	end->x = point.start.x + 1;
	end->y = point.start.y;
	f_bresen(fdf, point, *end);
}

static	void	draw_left_segment(t_fdf *fdf, t_bresen point, t_vec2 *end)
{
	end->x = point.start.x;
	end->y = point.start.y + 1;
	f_bresen(fdf, point, *end);
}
