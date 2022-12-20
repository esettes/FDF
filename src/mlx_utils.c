/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:14:04 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/20 16:40:07 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "MLX42.h"

void			draw_controls_info(t_fdf *fdf);
static t_vec2	set_img_offset(void);

void	loop_fdf(t_fdf *fdf)
{
	mlx_scroll_hook(fdf->mlx, &set_control_zoom, fdf);
	mlx_key_hook(fdf->mlx, &move_img, fdf);
	mlx_loop(fdf->mlx);
}

int	create_image(t_fdf *fdf, int start)
{
	int		i;
	int		j;
	t_vec2	offset;

	i = 50;
	if (start != 0)
		mlx_delete_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH * 1.3, HEIGHT * 1.7);
	offset = set_img_offset();
	mlx_image_to_window(fdf->mlx, fdf->img, offset.x, offset.y);
	while (i < WIDTH)
	{
		j = 50;
		while (j < HEIGHT + 50)
		{
			mlx_put_pixel(fdf->img, i, j, 0x121212FF);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	draw_image(t_fdf *fdf)
{
	set_new_zoom(fdf);
	if (print_map(fdf))
		return (EXIT_FAILURE);
	draw_menu(fdf);
	draw_controls_info(fdf);
	draw_menu_box(fdf);
	return (EXIT_SUCCESS);
}

int	modify_mesh(t_fdf *fdf)
{
	if (create_image(fdf, 1))
	{
		ft_putendl_fd(RED_, "Error: Image creation failed.", 1);
		return (EXIT_FAILURE);
	}
	if (draw_image(fdf))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static t_vec2	set_img_offset(void)
{
	t_vec2	offset;

	offset.x = -70;
	offset.y = -70;
	return (offset);
}
