/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:33:23 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/07 21:32:58 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# include "structs.h"

/* Include that functions which are called directly from inputs */

double	get_iso_pos_x(t_map map);
double	get_iso_pos_y(t_map map);
void	set_control_zoom(double x_delta, double y_delta, void *fdf_void);
void	set_new_zoom(t_fdf *fdf);
void	move_img(mlx_key_data_t keydata, void* param);
void	rotate_point(t_fdf *fdf, t_bresen *point, t_vec2 *end);

void	rotate_top_on_y(t_fdf *fdf, t_bresen *point, t_vec2 *end);
void	rotate_top_on_y_3d(t_fdf *fdf, t_bresen *point, t_vec2 *end);

#endif