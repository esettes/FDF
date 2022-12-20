/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/20 04:06:01 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_fdf *fdf)
{
	t_vec2	aux;

	aux.x = WIDTH - (WIDTH * 0.26);
	aux.y = HEIGHT - (HEIGHT * 0.999);
	mlx_put_string(fdf->mlx, "CONTROLS", aux.x + 10, aux.y += 25);
	mlx_put_string(fdf->mlx, "Mouse scroll to zoom", aux.x + 10, aux.y += 25);
	mlx_put_string(fdf->mlx, "Arrows to move map", aux.x + 10, aux.y += 25);
	mlx_put_string(fdf->mlx, "(0-5) Color palettes", aux.x + 10, aux.y += 25);
	mlx_put_string(fdf->mlx, "(I/T) Isometric/Top", aux.x + 10,
		aux.y += 25);
	mlx_put_string(fdf->mlx, "(Z/X) Y-Rotation", aux.x + 10, aux.y += 25);
	mlx_put_string(fdf->mlx, "(V/B) Resolution", aux.x + 10, aux.y += 25);
	mlx_put_string(fdf->mlx, "(N/M) Height", aux.x + 10, aux.y += 25);
}

void	draw_menu_box(t_fdf *fdf)
{
	int	i;
	int	j;

	i = WIDTH - (WIDTH * 0.21);
	while (i < MAX_WIDTH)
	{
		j = 0;
		while (j < MAX_HEIGHT)
		{
			mlx_put_pixel(fdf->img, i, j, 0x121212FF);
			j++;
		}
		i++;
	}
}

void	draw_controls_info(t_fdf *fdf)
{
	t_vec2		aux;
	t_menu		m;

	m.res = ft_strjoin(" Res ", ft_itoa((int)fdf->control.points_resolution));
	m.height = ft_strjoin("H ", ft_itoa((int)fdf->control.height));
	m.position = ft_strjoin(ft_strjoin(ft_itoa(fdf->control.horiz), " x "),
		ft_strjoin( ft_itoa(fdf->control.vert), " y"));
	m.zoom = ft_strjoin(" Z ", ft_itoa((int)fdf->control.zoom));
	m.all = ft_strjoin(ft_strjoin(m.position, m.res),
		ft_strjoin(m.height, m.zoom));
	aux.x = WIDTH - (WIDTH * 0.26);
	aux.y = HEIGHT - (HEIGHT * 0.17);
	mlx_put_string(fdf->mlx, ft_strjoin(m.position, m.res),
		aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, ft_strjoin(m.height, m.zoom),
		aux.x + 10, aux.y += 22);
	free(m.all);
}
