/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:53:25 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/22 23:53:27 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * Change palette index
*/
void	set_control_palette(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_0)
		fdf->control.palette = 0;
	if (keydata.key == MLX_KEY_1)
		fdf->control.palette = 1;
	if (keydata.key == MLX_KEY_2)
		fdf->control.palette = 2;
	if (keydata.key == MLX_KEY_3)
		fdf->control.palette = 3;
    if (keydata.key == MLX_KEY_4)
		fdf->control.palette = 4;
	modify_mesh(fdf);
}

/*
 * Modifyies mesh if exact key is pressed
*/
void	set_control_movement(mlx_key_data_t keydata, t_fdf *fdf)
{
    if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		fdf->control.vert -= 5;
		modify_mesh(fdf);
	}
	if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{
		fdf->control.vert += 5;
		modify_mesh(fdf);
	}
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		fdf->control.horiz -= 5;
		modify_mesh(fdf);
	}
	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		fdf->control.horiz += 5;
		modify_mesh(fdf);
	}
}

void	set_control_view(mlx_key_data_t keydata, t_fdf *fdf)
{
    if (keydata.key == MLX_KEY_T)
		fdf->control.perspective = TOP_VIEW;
	if (keydata.key == MLX_KEY_I)
		fdf->control.perspective = ISOMETRIC;
    modify_mesh(fdf);
}

void	set_control_zoom(double x_delta, double y_delta, void *fdf_void)
{
	t_fdf	*fdf;
	
	fdf = (t_fdf *)fdf_void;
	if (y_delta > 0)
	{
		if (fdf->control.zoom <= 150)
			fdf->control.zoom += 1;
	}
	else if (y_delta < 0)
	{
		if (fdf->control.zoom >= 0)
			fdf->control.zoom -= 1;
	}
	if (x_delta < 0)
	{
		if (fdf->control.zoom <= 150)
			fdf->control.zoom += 1;
	}
	else if (x_delta > 0)
	{
		if (fdf->control.zoom >= 0)
			fdf->control.zoom -= 1;
	}
	modify_mesh(fdf);
}

/*
 * Modifyies mesh if exact key is pressed and value is in range
*/
void	set_control_point_resolution(mlx_key_data_t keydata, t_fdf *fdf)
{
	if (keydata.key == MLX_KEY_V)
	{
		if (fdf->control.points_resolution >= 1)
		{
			fdf->control.points_resolution -= 1;
			modify_mesh(fdf);
		}
	}
	if (keydata.key == MLX_KEY_B)
	{
		if (fdf->control.points_resolution <= 12)
		{
			fdf->control.points_resolution += 1;
			modify_mesh(fdf);
		}
	}
}
