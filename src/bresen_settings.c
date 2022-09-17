#include "fdf.h"

void	set_bresen_step_increment(t_vec2 *step, t_iter max)
{
	step->x /= max.i + ADDIT_STEPS;
	step->y /= max.i + ADDIT_STEPS;
}

void	set_perspective(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth)
{
	if (fdf->control.perspective == ISOMETRIC)
		isometric(fdf, start, end, depth);
}

void	set_bresen_depth(t_fdf *fdf, t_depth *depth, t_vec2 start, t_vec2 end)
{
	depth->z = fdf->map.map[(int)start.y][(int)start.x] * fdf->control.height;
	depth->z1 = fdf->map.map[(int)end.y][(int)end.x] * fdf->control.height;
}

void	set_bresen_step(t_vec2 *step, t_vec2 start, t_vec2 end)
{
	step->x = (end.x - start.x);
	step->y = (end.y - start.y);
}

void	set_bresen_offset(t_fdf *fdf, t_vec2 *off)
{
    t_vec2  iso_offset;
    int     top_offset;

    iso_offset.y = 3.5;
    iso_offset.x = 9;
    top_offset = 2;
    if (fdf->control.perspective == ISOMETRIC)
	{
        off->x = IMG_CENTER_X - (fdf->map.px_size.x / iso_offset.x);
        off->y = IMG_CENTER_Y - (fdf->map.px_size.y / iso_offset.y);
    }
    else if (fdf->control.perspective == TOP_VIEW)
    {
        off->x = IMG_CENTER_X - (fdf->map.px_size.x / top_offset);
        off->y = IMG_CENTER_Y - (fdf->map.px_size.y / top_offset);
    }
}
