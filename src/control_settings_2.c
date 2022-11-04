/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_settings_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:53:17 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/22 23:53:19 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    set_control_rotation(mlx_key_data_t keydata, t_fdf *fdf)
{
    if (keydata.key == MLX_KEY_Z)
		fdf->control.rot_angle += 0.04;
	if (keydata.key == MLX_KEY_X)
		fdf->control.rot_angle -= 0.04;
	modify_mesh(fdf);
}

void    set_control_height(mlx_key_data_t keydata, t_fdf *fdf)
{
    if (keydata.key == MLX_KEY_KP_SUBTRACT || keydata.key == MLX_KEY_MINUS || keydata.key == MLX_KEY_N || keydata.key == MLX_KEY_PAGE_DOWN)
	{
		fdf->control.height -= 0.02;
		modify_mesh(fdf);
	}
	if (keydata.key == MLX_KEY_KP_ADD || keydata.key == MLX_KEY_PAGE_UP || keydata.key == MLX_KEY_M)
	{
		fdf->control.height += 0.02;
		modify_mesh(fdf);
	}
}