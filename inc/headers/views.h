/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:29:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/09 23:03:29 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWS_H
# define VIEWS_H

# include "structs.h"

void	print_map(t_fdf *fdf);
void	zoom(t_fdf *fdf);
float	f_max(float a, float b);
float	f_mod(float a);
int		check_image_limits(t_vec2 start, t_vec2 end, t_vec2 offset);

#endif