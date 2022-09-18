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

static t_vec2	set_img_offset(void);

void	loop_fdf(t_fdf *fdf)
{
	mlx_scroll_hook(fdf->mlx, &set_control_zoom, fdf);
	//mlx_loop_hook(fdf->mlx, &move_img, fdf->mlx);
	mlx_key_hook(fdf->mlx, &move_img, fdf);
	//draw_menu(fdf);
	mlx_loop(fdf->mlx);
	//mlx_delete_image(fdf->mlx, fdf->img); // Once app request exit, cleanup.
	mlx_terminate(fdf->mlx);
}

int	create_image(t_fdf *fdf)
{
	t_vec2	offset;

	if (fdf->img)
		mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH * IMG_AUMENT, HEIGHT * IMG_AUMENT);
	offset = set_img_offset();
	ft_memset(fdf->img->pixels, 0, fdf->img->width * fdf->img->height * 4);
	mlx_image_to_window(fdf->mlx, fdf->img, -offset.x, -offset.y);
	return (EXIT_SUCCESS);
}

int		draw_image(t_fdf *fdf)
{
	set_new_zoom(fdf);
	if (print_map(fdf))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int		modify_mesh(t_fdf *fdf)
{
	if (create_image(fdf))
	{
		ft_putendl_fd(RED_, "Error: Image creation failed.", 1);
		return (EXIT_FAILURE);
	}
	if(draw_image(fdf))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static t_vec2	set_img_offset(void)
{
	t_vec2	offset;

	offset.x  = ((WIDTH * IMG_AUMENT) / 2) - (WIDTH / 2);
	offset.y  = ((HEIGHT * IMG_AUMENT) / 2) - (HEIGHT / 2);
	return (offset);
}