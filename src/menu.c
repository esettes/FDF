/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/19 02:25:44 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_info(t_fdf fdf);

void	draw_menu(t_fdf *fdf)
{
	t_vec2	aux;

	aux.x = WIDTH - (WIDTH * 0.20);
	aux.y = HEIGHT - (HEIGHT * 0.90);
	mlx_put_string(fdf->mlx, "CONTROLS", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[mouse] Scroll to zoom", aux.x + 10,
		aux.y += 22);
	mlx_put_string(fdf->mlx, "[arrows] Move map", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[0-5] Color palettes", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[I/T] Isometric/Top view", aux.x + 10,
		aux.y += 22);
	mlx_put_string(fdf->mlx, "[Z/X] Y-Rotation", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[V/B] Resolution", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, "[N/M] Height", aux.x + 10, aux.y += 22);
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
	//draw_info(*fdf);
}

void	draw_info(t_fdf fdf)
{
	t_vec2	aux;

	aux.x = WIDTH - (WIDTH * 0.30);
	aux.y = HEIGHT - (HEIGHT * 0.20);
	mlx_put_string(fdf.mlx, "Height", aux.x + 10, aux.y += 22);
	mlx_put_string(fdf.mlx, ft_itoa((int)fdf.control.height), aux.x + 10, aux.y += 22);
}
