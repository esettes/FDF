/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/18 00:20:04 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_fdf *fdf)
{
	t_vec2	aux;

	aux.x = (WIDTH * IMG_AUMENT) / IMG_AUMENT - (WIDTH * 0.20);
	aux.y = (HEIGHT * IMG_AUMENT) / IMG_AUMENT - (HEIGHT * 0.40);
	mlx_put_string(fdf->mlx, "CONTROLS", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[mouse] Scroll to zoom", aux.x + 10,
		aux.y += 22);
	mlx_put_string(fdf->mlx, "[W/A/S/D] Move map", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[I/T] Isometric/Top view", aux.x + 10,
		aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[0-2] Color palette", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[Z/X] Y-Rotation", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[-/+] Height multip.", aux.x + 10, aux.y += 22);
}

void	draw_menu_box(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 1750;
	while (i < MAX_WIDTH + 300)
	{
		j = 100;
		while (j < MAX_HEIGHT + 100)
		{
			mlx_put_pixel(fdf->img, i, j, 0xdecd51);
			j++;
		}
		i++;
	}
}
