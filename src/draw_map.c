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

void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end);

void	print_map(t_fdf *fdf)
{
	t_vec2	coord;
	t_vec2	h_end;
	t_vec2	v_end;

	coord.y = 0;
	while (coord.y < fdf->map.vertices.y)
	{
		coord.x = 0;
		while (coord.x < fdf->map.vertices.x)
		{
			if (coord.x < fdf->map.vertices.x - 1)
			{
				v_end.y = coord.y;
				v_end.x = coord.x + 1;
				//printf("coord.x: %d, ", coord.x);
				//printf("y: %d\n", coord.x);
				f_bresen(fdf, coord, v_end);
			}
			if (coord.y < fdf->map.vertices.y - 1)
			{
				h_end.x = coord.x;
				h_end.y = coord.y + 1;
				f_bresen(fdf, coord, h_end);
			}
			coord.x++;
		}
		coord.y++;
	}
}

void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end)
{
	t_vec2	step;
	t_iter	max;
	t_vec2	offset;
	t_depth	depth;
	t_iter	curr;

	get_current_position(start, &curr);
	set_bresen_depth(fdf, &depth, start, end);
	set_control_zoom(fdf, &start, &end);
	set_bresen_offset(fdf, &offset);
	
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

void	set_color_array(t_fdf *fdf)
{
	fdf->map.colors = (int **)malloc(sizeof(int *) * fdf->map.vertices.y);
	fdf->map.colors[0] = (int *)malloc(sizeof(int) * fdf->map.vertices.x);
	fdf->map.colors[0][0] = 0x00FF00;
	fdf->map.colors[0][1] = 0x00FF00;
}

void	palette_colormap(t_fdf *fdf)
{

}

void	set_rotate_point_to_origin(t_fdf *fdf, t_vec2 *start, t_vec2 *end)
{
	start->x -= fdf->map.px_size.x / fdf->map.offset.x;
	start->y -= fdf->map.px_size.y / fdf->map.offset.y;
	end->x -= fdf->map.px_size.x / fdf->map.offset.x;
	end->y -= fdf->map.px_size.y / fdf->map.offset.y;
}




void	rotate_on_y(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth *depth)
{
	t_vec2	rot_start;
	t_vec2	rot_end;
	t_depth	rot_depth;

	set_rotate_point_to_origin(fdf, start, end);
	rot_start.x = start->x;
	rot_start.y = start->y;
	rot_end.x = end->x;
	rot_end.y = end->y;
	rot_depth.z = depth->z;
	rot_depth.z1 = depth->z1;
	start->x = (rot_start.x * cosf(fdf->control.rot_angle)) - (rot_start.y * sinf(fdf->control.rot_angle));
	start->y = (rot_start.y * cosf(fdf->control.rot_angle)) + (rot_start.x * sinf(fdf->control.rot_angle));
	end->x = (rot_end.x * cosf(fdf->control.rot_angle)) - (rot_end.y * sinf(fdf->control.rot_angle));
	end->y = (rot_end.y * cosf(fdf->control.rot_angle)) + (rot_end.x * sinf(fdf->control.rot_angle));
	depth->z = rot_depth.z;// * cos(fdf->control.rot_angle) - rot_depth.z1 * sin(fdf->control.rot_angle);
	depth->z1 = rot_depth.z1;// * cos(fdf->control.rot_angle) + rot_depth.z * sin(fdf->control.rot_angle);
}

void	rotate_top_on_y_3d(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth *depth)
{
	t_vec2	rot_start;
	t_vec2	rot_end;
	t_depth	rot_depth;

	set_rotate_point_to_origin(fdf, start, end);
	rot_start.x = start->x;
	rot_start.y = start->y;
	rot_end.x = end->x;
	rot_end.y = end->y;
	rot_depth.z = depth->z;
	rot_depth.z1 = depth->z1;
	start->x = rot_start.x * cos(1) - rot_start.y * sin(fdf->control.rot_angle) ;
	start->y = rot_start.y * cos(fdf->control.rot_angle) + rot_start.x * sin(45);// * sin(fdf->control.rot_angle);
	end->x = rot_end.x  * cos(1) - rot_end.y * sin(fdf->control.rot_angle);
	end->y = rot_end.y * cos(fdf->control.rot_angle) + rot_end.x * sin(45);
	depth->z = rot_depth.z;// * cos(fdf->control.rot_angle) - rot_depth.z1 * sin(fdf->control.rot_angle);
	depth->z1 = rot_depth.z1;// * cos(fdf->control.rot_angle) + rot_depth.z * sin(fdf->control.rot_angle);
}

// void	rotate_top_on_y_3d(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth *depth)
// {
// 	t_vec2	rot_start;
// 	t_vec2	rot_end;
// 	t_depth	rot_depth;

// 	set_rotate_point_to_origin(fdf, start, end);
// 	rot_start.x = start->x;
// 	rot_start.y = start->y;
// 	rot_end.x = end->x;
// 	rot_end.y = end->y;
// 	rot_depth.z = depth->z;
// 	rot_depth.z1 = depth->z1;
// 	start->x = rot_start.x * cos(1) - rot_start.y * sin(fdf->control.rot_angle) ;
// 	start->y = rot_start.y * cos(fdf->control.rot_angle) + rot_start.x * sin(1);// * sin(fdf->control.rot_angle);
// 	end->x = rot_end.x  * cos(1) - rot_end.y * sin(fdf->control.rot_angle);
// 	end->y = rot_end.y * cos(fdf->control.rot_angle) + rot_end.x * sin(1);
// 	depth->z = rot_depth.z;// * cos(fdf->control.rot_angle) - rot_depth.z1 * sin(fdf->control.rot_angle);
// 	depth->z1 = rot_depth.z1;// * cos(fdf->control.rot_angle) + rot_depth.z * sin(fdf->control.rot_angle);
// }


/* NOTE valid */
void	rotate_top_on_y(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth *depth)
{
	t_vec2	rot_start;
	t_vec2	rot_end;
	t_depth	rot_depth;

	set_rotate_point_to_origin(fdf, start, end);
	rot_start.x = start->x;
	rot_start.y = start->y;
	rot_end.x = end->x;
	rot_end.y = end->y;
	rot_depth.z = depth->z;
	rot_depth.z1 = depth->z1;
	start->x = rot_start.x - rot_start.y * sin(fdf->control.rot_angle);
	start->y = rot_start.y * sin(fdf->control.rot_angle) + rot_start.x;// * sin(fdf->control.rot_angle);
	end->x = rot_end.x - rot_end.y * sin(fdf->control.rot_angle);
	end->y = rot_end.y * sin(fdf->control.rot_angle) + rot_end.x;// * sin(fdf->control.rot_angle);
	depth->z = rot_depth.z;// * cos(fdf->control.rot_angle) - rot_depth.z1 * sin(fdf->control.rot_angle);
	depth->z1 = rot_depth.z1;// * cos(fdf->control.rot_angle) + rot_depth.z * sin(fdf->control.rot_angle);
}





/* NOTE valid */
void	rotate_point(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth *depth)
{
	t_vec2	rot_start;
	t_vec2	rot_end;
	t_depth	rot_depth;

	set_rotate_point_to_origin(fdf, start, end);
	rot_start.x = start->x;
	rot_start.y = start->y;
	rot_end.x = end->x;
	rot_end.y = end->y;
	rot_depth.z = depth->z;
	rot_depth.z1 = depth->z1;
	start->x = rot_start.x * cosf(fdf->control.rot_angle) + rot_start.y * sinf(fdf->control.rot_angle);
	start->y = rot_start.y * cosf(fdf->control.rot_angle) - rot_start.x * sinf(fdf->control.rot_angle);
	end->x = rot_end.x * cosf(fdf->control.rot_angle) + rot_end.y * sinf(fdf->control.rot_angle);
	end->y = rot_end.y * cosf(fdf->control.rot_angle) - rot_end.x * sinf(fdf->control.rot_angle);
	depth->z = rot_depth.z;
	depth->z1 = rot_depth.z1;
}



// void	free_current_color_array(t_fdf *fdf)
// {
// 	t_iter	iter;

// 	iter.i = 0;
// 	iter.j = 0;
// 	while (iter.i < fdf->map.vertices.y)
// 	{
// 		while (iter.j < fdf->map.vertices.y)
// 		{
// 			free(fdf->map.colors[i]);
// 			i++;
// 		}
// 	}
// 	free(fdf->map.colors);
// }