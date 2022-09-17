/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:14:04 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/12 19:59:18 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	loop_fdf(t_fdf *fdf)
{
	mlx_scroll_hook(fdf->mlx, &set_zoom, fdf);
	//mlx_loop_hook(fdf->mlx, &move_img, fdf->mlx);
	mlx_key_hook(fdf->mlx, &move_img, fdf);
	//draw_menu(fdf);
	mlx_loop(fdf->mlx);
	//mlx_delete_image(fdf->mlx, fdf->img); // Once app request exit, cleanup.
	mlx_terminate(fdf->mlx);
}

void	create_image(t_fdf *fdf)
{
	t_vec2	offset;

	if (fdf->img)
	{
		mlx_delete_image(fdf->mlx, fdf->img);
	}
	fdf->img = mlx_new_image(fdf->mlx, WIDTH * IMG_AUMENT, HEIGHT * IMG_AUMENT);
	offset.x  = ((WIDTH * IMG_AUMENT) / 2) - (WIDTH /2);
	offset.y  = ((HEIGHT * IMG_AUMENT) / 2) - (HEIGHT /2);
	//ft_memset(fdf->img->pixels, -16581375, fdf->img->width * fdf->img->height * 4);
	mlx_image_to_window(fdf->mlx, fdf->img, -offset.x, -offset.y);
}

void	draw_image(t_fdf *fdf)
{
	set_new_zoom(fdf);
	print_map(fdf);
}

void	modify_mesh(t_fdf *fdf)
{
	create_image(fdf);
	draw_image(fdf);
}
