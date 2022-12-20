/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:53:35 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/20 04:04:31 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth)
{
	float	z_zoom;

	z_zoom = 0.7;
	start->x = (start->x - start->y) * (cos(45) * 1);
	start->y = (start->x + start->y) * (sin(45) * z_zoom)
		- (depth.z * (fdf->control.zoom * 0.004));
	end->x = (end->x - end->y) * (cos(45) * 1);
	end->y = (end->x + end->y) * (sin(45) * z_zoom)
		- (depth.z1 * (fdf->control.zoom * 0.004));
	(void)fdf;
}

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
