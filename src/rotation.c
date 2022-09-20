#include "fdf.h"

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
void	rotate_point(t_fdf *fdf, t_bresen *point, t_vec2 *end)
{
	t_vec2	rot_start;
	t_vec2	rot_end;
	t_depth	rot_depth;

	set_rotate_point_to_origin(fdf, &point->start, end);
	rot_start.x = point->start.x;
	rot_start.y = point->start.y;
	rot_end.x = end->x;
	rot_end.y = end->y;
	rot_depth.z = point->depth.z;
	rot_depth.z1 = point->depth.z1;
	point->start.x = rot_start.x * cosf(fdf->control.rot_angle) + rot_start.y * sinf(fdf->control.rot_angle);
	point->start.y = rot_start.y * cosf(fdf->control.rot_angle) - rot_start.x * sinf(fdf->control.rot_angle);
	end->x = rot_end.x * cosf(fdf->control.rot_angle) + rot_end.y * sinf(fdf->control.rot_angle);
	end->y = rot_end.y * cosf(fdf->control.rot_angle) - rot_end.x * sinf(fdf->control.rot_angle);
	point->depth.z = rot_depth.z;
	point->depth.z1 = rot_depth.z1;
}
