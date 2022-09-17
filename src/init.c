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

void	open_fd(t_fdf *fdf, char *raw_map);

void	init_mlx(t_fdf *fdf, char *raw_map)
{
	fdf->control.zoom = 2;
	fdf->control.rot_angle = 0;
	fdf->control.height = 1;
	fdf->control.vert = 1;
	fdf->control.horiz = 1;
	fdf->control.perspective = ISOMETRIC;// TOP_VIEW;
	//set_map_info(fdf, raw_map);
	open_fd(fdf, raw_map);
	obtain_split_fd(fdf->fd, &fdf->map);
	
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "Wire-frame (fdf)", true);
	create_image(fdf);
	draw_menu(fdf);
	draw_image(fdf);
	loop_fdf(fdf);
}

void	open_fd(t_fdf *fdf, char *raw_map)
{
	fdf->fd = open(raw_map, O_RDONLY);
	if (fdf->fd < 0)
	{
		printf("Error: File not found.\n");
		exit(0);
	}
}