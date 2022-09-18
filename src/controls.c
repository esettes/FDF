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

void	set_control_point_resolution(mlx_key_data_t keydata, t_fdf *fdf);
void	set_control_palette(mlx_key_data_t keydata, t_fdf *fdf);
void	set_control_movement(mlx_key_data_t keydata, t_fdf *fdf);
void	set_control_view(mlx_key_data_t keydata, t_fdf *fdf);
void    set_control_rotation(mlx_key_data_t keydata, t_fdf *fdf);
void    set_control_height(mlx_key_data_t keydata, t_fdf *fdf);

void	move_img(mlx_key_data_t keydata, void* param)
{
	t_fdf	*fdf;
	keys_t	key;

	fdf = param;
	key = keydata.key;
	if (key == MLX_KEY_A && keydata.action == MLX_RELEASE && keydata.modifier == MLX_CONTROL)
		puts("Gotta grab it all!");
	if (key == MLX_KEY_ESCAPE)
		mlx_close_window(fdf->mlx);
	if (key >= 262 && key <= 265 || key >= 87 && key <= 65)
		set_control_movement(keydata, fdf);
	else if (key == MLX_KEY_T || key == MLX_KEY_I)
		set_control_view(keydata, fdf);
	else if (key == 333 || key == 45 || key == 267 || key == 334 || key == 266)
		set_control_height(keydata, fdf);
	else if (key == MLX_KEY_Z || key == MLX_KEY_X)
		set_control_rotation(keydata, fdf);
	else if (key >= MLX_KEY_0 && key <= MLX_KEY_3)
		set_control_palette(keydata, fdf);
	else if (key >= MLX_KEY_F1 && key <= MLX_KEY_F2)
		set_control_point_resolution(keydata, fdf);
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
