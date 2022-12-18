/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:01:03 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/11 10:19:20 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_UTILS_H
# define DRAW_UTILS_H

# include "structs.h"

void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth);
float	f_max(float a, float b);
float	f_abs(float a);
int 	print_map(t_fdf *fdf);

void	set_perspective(t_fdf *fdf, t_bresen *point, t_vec2 *end);
void	set_bresen_step_increment(int addit_steps, t_vec2 *step, t_iter max);
void	set_draw_control_zoom(t_fdf *fdf, t_vec2 *start, t_vec2 *end);
void	set_draw_control_movement(t_fdf *fdf, t_vec2 *start, t_vec2 *end);
t_vec2	set_bresen_offset(t_fdf *fdf);
void	set_bresen_depth(t_fdf *fdf, t_bresen *point, t_vec2 end);
void	set_bresen_step(t_bresen *point, t_vec2 end);

int		check_image_limits(t_bresen *point, t_vec2 end);
void	step_increment(t_vec2 *start, t_vec2 step);
void	get_current_position(t_vec2 start, t_iter *current);
void	change_height(t_fdf *fdf);;

#endif