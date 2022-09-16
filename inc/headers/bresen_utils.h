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

#ifndef BRESEN_UTILS_H
# define BRESEN_UTILS_H

# include "structs.h"

/**
 * Applies zoom of each start and end points.
 */
void	bresen_zoom(t_fdf *fdf, t_vec2 *start, t_vec2 *end);
void	f_bresen(t_fdf *fdf, t_vec2 start, t_vec2 end, int direction);
void	isometric(t_fdf *fdf, t_vec2 *start, t_vec2 *end, t_depth depth);
float	f_max(float a, float b);
float	f_abs(float a);
int		check_image_limits(t_vec2 start, t_vec2 end, t_vec2 offset);

#endif