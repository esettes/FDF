/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:54:33 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/11 10:22:42 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_delta_x(t_fdf *fdf)
{
	t_vec2	pos;
	int		i;
	int		error;
	t_lines	line;

	line = fdf->mtrx.line;
	error = ((int)line.delta.y << 1) - (int)line.delta.x;
	pos.x = (int)line.start.x + (int)line.step.x;
	pos.y = (int)line.start.y;
	mlx_put_pixel(fdf->img, line.start.x, line.start.y, line.color);
	while (i <= line.delta.x)
	{
		if (error > 0)
		{
			pos.y = line.step.y;
			error += (int)(line.delta.y - line.delta.x) << 1;
		}
		else
			error += (int)line.delta.y << 1;
		mlx_put_pixel(fdf->img, pos.x, pos.y, line.color);
		pos.x += line.step.x;
		i++;
	}
}

void	draw_delta_y(t_fdf *fdf)
{
	t_vec2	pos;
	int		i;
	int		error;
	t_lines	line;

	line = fdf->mtrx.line;
	error = ((int)line.delta.x << 1) - (int)line.delta.y;
	pos.x = (int)line.start.y + (int)line.step.y;
	pos.y = (int)line.start.x;
	mlx_put_pixel(fdf->img, line.start.x, line.start.y, line.color);
	while (i <= line.delta.y)
	{
		if (error > 0)
		{
			error += (int)(line.delta.x - line.delta.y) << 1;
			pos.x = line.step.x;
		}
		else
			error += (int)line.delta.x << 1;
		mlx_put_pixel(fdf->img, pos.x, pos.y, line.color);
		pos.y += line.step.y;
		i++;
	}
}

void	bresen_line(t_fdf *fdf)
{
	t_lines	line;

	line = fdf->mtrx.line;
	line.delta.x = abs((int)(line.end.x - line.start.x));
	line.delta.y = abs((int)(line.end.y - line.start.y));
	if (line.end.x >= line.start.x)
		line.step.x += 1;
	else
		line.step.x -= 1;
	if (line.end.y >= line.start.y)
		line.step.y += 1;
	else
		line.step.y -= 1;
	if (line.delta.x > line.delta.y)
		draw_delta_x(fdf);
	else
		draw_delta_y(fdf);
}