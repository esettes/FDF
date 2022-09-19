/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:24:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/12 19:03:16 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	open_fd(t_fdf *fdf, char *raw_map);

void	init_mlx(t_fdf *fdf, char *raw_map)
{
	fdf->control.palette = 0;
	fdf->control.zoom = 2;
	fdf->control.rot_angle = 0;
	fdf->control.points_resolution = ADDIT_STEPS;
	fdf->control.height = 1;
	fdf->control.vert = 1;
	fdf->control.horiz = 1;
	fdf->control.perspective = ISOMETRIC;// TOP_VIEW;
	//set_map_info(fdf, raw_map);
	open_fd(fdf, raw_map);
	obtain_split_fd(fdf->fd, &fdf->map);
	close(fdf->fd);
	if (!fdf->map.map)
	{
		ft_putendl_fd(RED_, "Error: Can't obtain map info.", 1);
		exit(EXIT_FAILURE);
		return ;
	}
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "Wire-frame (fdf)", true);
	if (!fdf->mlx)
	{
		ft_putendl_fd(RED_, "Error: Can't initialize mlx.", 1);
		exit(EXIT_FAILURE);
		return ;
	}
	create_image(fdf, 0);
	draw_menu(fdf);
	draw_image(fdf);
	loop_fdf(fdf);
}

static void	open_fd(t_fdf *fdf, char *raw_map)
{
	fdf->fd = open(raw_map, O_RDONLY);
	if (fdf->fd <= 0)
	{
		ft_putendl_fd(RED_, "Error: File not found.", 1);
		exit(EXIT_FAILURE);
		return ;
	}
}
