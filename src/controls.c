/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:51:18 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/12 16:52:53 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

mlx_image_t	*g_img;

void	move_img(mlx_key_data_t keydata, void* param)
{
	t_fdf	*fdf;

	fdf = param;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && keydata.modifier == MLX_CONTROL)
		puts("Gotta grab it all!");
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
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
	if (keydata.key == MLX_KEY_T)
	{
		fdf->control.perspective = TOP_VIEW;
		modify_mesh(fdf);
	}
	if (keydata.key == MLX_KEY_I)
	{
		fdf->control.perspective = ISOMETRIC;
		modify_mesh(fdf);
	}
	if (keydata.key == MLX_KEY_KP_SUBTRACT || keydata.key == MLX_KEY_MINUS || keydata.key == MLX_KEY_PAGE_DOWN)
	{
		fdf->control.height -= 0.02;
		modify_mesh(fdf);
	}
	if (keydata.key == MLX_KEY_KP_ADD || keydata.key == MLX_KEY_PAGE_UP)
	{
		fdf->control.height += 0.02;
		modify_mesh(fdf);
	}
	if (keydata.key == MLX_KEY_1)
	{
		fdf->control.rot_angle += 0.04;
		modify_mesh(fdf);
	}
	if (keydata.key == MLX_KEY_2)
	{
		fdf->control.rot_angle -= 0.04;
		modify_mesh(fdf);
	}
}

void	key_hook(void *param)
{
	//mlx_t	*mlx;
	t_fdf	*fdf;

	fdf = param;
	//mlx = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->img->instances[0].y -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->img->instances[0].y += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->img->instances[0].x -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->img->instances[0].x += 5;
}

void	set_zoom(double x_delta, double y_delta, void *fdf_void)
{
	t_fdf	*fdf;
	
	fdf = (t_fdf *)fdf_void;
	if (y_delta > 0)
	{
		if (fdf->control.zoom <= 100)
		{
			fdf->control.zoom += 1;
			modify_mesh(fdf);
		}
	}
	else if (y_delta < 0)
	{
		if (fdf->control.zoom >= 0)
		{
			fdf->control.zoom -= 1;
			modify_mesh(fdf);
		}
	}
	if (x_delta < 0)
	{
		if (fdf->control.zoom <= 100)
		{
			fdf->control.zoom += 1;
			modify_mesh(fdf);
		}
	}
	else if (x_delta > 0)
	{
		if (fdf->control.zoom >= 0)
		{
			fdf->control.zoom -= 1;
			modify_mesh(fdf);
		}
	}
}

// void	free_props(t_fdf *fdf)
// {
// 	if (fdf->mtrx.px_size)
// 		free (fdf->mtrx.px_size);
// 	if (fdf.mtrx.end_draw)
// 		free (fdf->mtrx.end_draw);
// 	if (fdf->mtrx.start_draw)
// 		free (fdf->mtrx.start_draw);
// }
