/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:37:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/17 23:41:18 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "macros.h"

// void	change_height_color(t_fdf *fdf)
// {
// 	int	i;
// 	int	j;
// 	int	val;

// 	i = 0;
// 	while (i < fdf->map.vertices.y)
// 	{
// 		j = 0;
// 		while (j < fdf->map.vertices.x)
// 		{
// 			if (fdf->control.palette == 0)
// 				val = fdf->map.default_colors[i][j];
// 			else
// 				val = fdf->map.map[i][j];
// 			set_color_palet(fdf->map.colors[i],
// 				get_color_palette(fdf->control.palette), j, val);
// 			j++;
// 		}
// 		i++;
// 	}
// }
// 	while (i < fdf->map.vertices.y)
// 	{
// 		j = 0;
// 		while (j < fdf->map.vertices.x)
// 		{
// 			if (fdf->map.map[i][j] > 0)
// 				fdf->map.map[i][j] += 1;
// 			else if (fdf->map.map[i][j] < 0)
// 				fdf->map.map[i][j] -= 1;
// 			j++;
// 		}
// 		i++;
// 	}
// 	{
// 		fdf->map.colors[i] = 0x00FF00;
// 		i++;
// 	}
// }

/* Asign new values for the fdf->map.map array of integers*/
void	change_height(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.vertices.y)
	{
		j = 0;
		while (j < fdf->map.vertices.x)
		{
			fdf->map.map[i][j] *= 0.5;
			j++;
		}
		i++;
	}
}

void	set_draw_control_zoom(t_fdf *fdf, t_vec2 *start, t_vec2 *end)
{
	start->x *= fdf->control.zoom;
	start->y *= fdf->control.zoom;
	end->x *= fdf->control.zoom;
	end->y *= fdf->control.zoom;
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
	int		min_x;
	int		min_y;
	t_vec2	offset;
	t_vec2	start;

	min_x = 500;
	min_y = 100;
	offset.x = point->offset.x;
	offset.y = point->offset.y;
	start.x = point->start.x;
	start.y = point->start.y;
	if ((end.x + offset.x < MAX_WIDTH) && (end.y + offset.y < MAX_HEIGHT)
		&& (end.x + offset.x > min_x) && (end.y + offset.y > min_y)
		&& (start.x + offset.x < MAX_WIDTH)
		&& (start.y + offset.y < MAX_HEIGHT)
		&& (start.x + offset.x > min_x) && (start.y + offset.y > min_y))
	{
		return (1);
	}
	return (0);
}
