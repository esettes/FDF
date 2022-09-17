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
void	set_zoom(double x_delta, double y_delta, void *fdf_void);
void	set_new_zoom(t_fdf *fdf);
void	move_img(mlx_key_data_t keydata, void* param);

#endif