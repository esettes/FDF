#include "fdf.h"

void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth)
{
	float	z_zoom;
	
	z_zoom = 0.5;
	if (z_zoom >= 0 && z_zoom <= 70)
		start->x = (start->x - start->y) * (cos(45) * 1);
		start->y = (start->x + start->y) * (sin(45) * z_zoom) 
            - (depth.z * z_zoom * (fdf->control.zoom * 0.2));
		end->x = (end->x - end->y) * (cos(45) * 1);
		end->y = (end->x + end->y) * (sin(45) * z_zoom) 
            - (depth.z1 * z_zoom * (fdf->control.zoom * 0.2));
	(void)fdf;
}
/*
 Advance in rotate 3d map vertically
 last function which I test rotation:
void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth)
{
	float	z_zoom;
	
	z_zoom = 0.5;
	if (z_zoom >= 0 && z_zoom <= 70)
		start->x = (start->x - start->y) * (cos(45) * 1);// * cos(fdf->control.rot_angle);
		start->y = (start->x + start->y) * (sin(45) * z_zoom) 
            - (depth.z * sin(fdf->control.rot_angle)*  z_zoom * (fdf->control.zoom * 0.2 ));
		end->x = (end->x - end->y) * (cos(45) * 1);// * cos(fdf->control.rot_angle);
		end->y = (end->x + end->y) * (sin(45) * z_zoom) 
            - (depth.z1 * sin(fdf->control.rot_angle) *  z_zoom * (fdf->control.zoom * 0.2 ));
	(void)fdf;
}

 void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth)
{
	float	z_zoom;
	
	z_zoom = 0.5;
	if (z_zoom >= 0 && z_zoom <= 70)
		start->x = (start->x - start->y) * (cos(45) * 1);// * cos(fdf->control.rot_angle);
		start->y = (start->x + start->y) * (sin(45) * z_zoom) 
            - (depth.z *  z_zoom * (fdf->control.zoom * sin(fdf->control.rot_angle)));
		end->x = (end->x - end->y) * (cos(45) * 1);// * cos(fdf->control.rot_angle);
		end->y = (end->x + end->y) * (sin(45) * z_zoom) 
            - (depth.z1 *  z_zoom * (fdf->control.zoom * sin(fdf->control.rot_angle)));
	(void)fdf;
}

void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth)
{
	float	z_zoom;
	
	z_zoom = 0.5;
	if (z_zoom >= 0 && z_zoom <= 70)
		start->x = (start->x - start->y) * (cos(45) * 1) * cos(fdf->control.rot_angle);
		start->y = (start->x + start->y) * (sin(45) * z_zoom) 
            - (depth.z *  z_zoom * (fdf->control.zoom * 0.2)) * sin(fdf->control.rot_angle);
		end->x = (end->x - end->y) * (cos(45) * 1) * cos(fdf->control.rot_angle);
		end->y = (end->x + end->y) * (sin(45) * z_zoom) 
            - (depth.z1 *  z_zoom * (fdf->control.zoom * 0.2)) * sin(fdf->control.rot_angle);
	(void)fdf;
}
*/

void	step_increment(t_vec2 *start, t_vec2 step)
{
	start->x += step.x;
	start->y += step.y;
}

void	get_current_position(t_vec2 start, t_iter *current)
{
	current->i = (int)start.x;
	current->j = (int)start.y;
}