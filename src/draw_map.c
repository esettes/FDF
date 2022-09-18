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

void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end, t_vec2 offset);
static	int	draw_right_segment(t_fdf *fdf, t_vec2 *st, t_vec2 *en, t_vec2 off);
static	int	draw_left_segment(t_fdf *fdf, t_vec2 *st, t_vec2 *en, t_vec2 off);

int	print_map(t_fdf *fdf)
{
	t_vec2	start;
	t_vec2	h_end;
	t_vec2	v_end;
	t_vec2	offset;

	start.y = 0;
	//if (!set_color_array(fdf))
	//	return ;
	set_color_array(fdf);
	set_bresen_offset(fdf, &offset);
	while (start.y < fdf->map.vertices.y)
	{
		start.x = 0;
		while (start.x < fdf->map.vertices.x)
		{
			if (start.x < fdf->map.vertices.x - 1)
			{
				if (draw_right_segment(fdf, &start, &v_end, offset))
					return (EXIT_FAILURE);
			}
			if (start.y < fdf->map.vertices.y - 1)
			{
				if (draw_left_segment(fdf, &start, &h_end, offset))
					return (EXIT_FAILURE);
			}
			start.x++;
		}
		start.y++;
	}
	return (EXIT_SUCCESS);
}

void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end, t_vec2 offset)
{
	t_vec2	step;
	t_iter	max;
	t_depth	depth;
	t_iter	curr;

	get_current_position(start, &curr);
	set_bresen_depth(fdf, &depth, start, end);
	set_control_zoom(fdf, &start, &end);
	set_perspective(fdf, &start, &end, depth);
	rotate_point(fdf, &start, &end, &depth);
	//rotate_top_on_y_3d(fdf, &start, &end, &depth);
	set_control_movement(fdf, &start, &end);
	set_bresen_step(&step, start, end);
	max.i = f_max(f_abs(step.x), f_abs(step.y));
	set_bresen_step_increment(&step, max);
	max.j = 0;
	while (max.j++ <= max.i + ADDIT_STEPS)
	{
		if (check_image_limits(start, end, offset))
			mlx_put_pixel(fdf->img, start.x + offset.x , start.y + offset.y, 
			fdf->map.colors[curr.j][curr.i]);
		step_increment(&start, step);
	}
}

static	int	draw_right_segment(t_fdf *fdf, t_vec2 *st, t_vec2 *en, t_vec2 off)
{
	t_vec2	end;

	en->x = st->x + 1;
	en->y = st->y;
	f_bresen(fdf, *st, *en, off);
	// TODO check if can return FALSE
	return (EXIT_SUCCESS);
}

static	int	draw_left_segment(t_fdf *fdf, t_vec2 *st, t_vec2 *en, t_vec2 off)
{
	t_vec2	end;

	en->x = st->x;
	en->y = st->y + 1;
	f_bresen(fdf, *st, *en, off);
	// TODO check if can return FALSE
	return (EXIT_SUCCESS);
}
