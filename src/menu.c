/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:29:11 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/20 16:39:49 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "macros.h"
#include "libft.h"
#include <stddef.h>
#include "MLX42.h"

void	free_menu_info(t_menu *m);

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
	t_vec2	aux;
	t_menu	m;
	char	*aux1;
	char	*aux2;

	m.itoares = ft_itoa((int)fdf->control.points_resolution);
	m.itoaheight = ft_itoa((int)fdf->control.height);
	m.itoahoriz = ft_itoa((int)fdf->control.horiz);
	m.itoavert = ft_itoa((int)fdf->control.vert);
	m.itoazoom = ft_itoa((int)fdf->control.zoom);
	m.horiz = ft_strjoin(m.itoahoriz, " x ");
	m.vert = ft_strjoin(m.itoavert, " y");
	m.res = ft_strjoin(" Res ", m.itoares);
	m.height = ft_strjoin("H ", m.itoaheight);
	m.position = ft_strjoin(m.horiz, m.vert);
	m.zoom = ft_strjoin(" Z ", m.itoazoom);
	aux1 = ft_strjoin(m.position, m.res);
	aux2 = ft_strjoin(m.height, m.zoom);
	aux.x = WIDTH - (WIDTH * 0.26);
	aux.y = HEIGHT - (HEIGHT * 0.17);
	mlx_put_string(fdf->mlx, aux1, aux.x + 10, aux.y += 22);
	mlx_put_string(fdf->mlx, aux2, aux.x + 10, aux.y += 22);
	free_menu_info(&m);
	free(aux1);
	free(aux2);
}

void	free_menu_info(t_menu *m)
{
	free(m->itoaheight);
	free(m->itoahoriz);
	free(m->itoavert);
	free(m->itoares);
	free(m->itoazoom);
	free(m->horiz);
	free(m->vert);
	free(m->res);
	free(m->height);
	free(m->position);
	free(m->zoom);
}
