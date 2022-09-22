/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:54:06 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/22 23:54:07 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PALETTES_H
# define PALETTES_H

# include "structs.h"

void	palette_default(int *arr, int pos, int z_value);
void	palette_terrain(int *arr, int pos, int z_value);
void	palette_test(int *arr, int pos, int z_value);
void	palette_gamma(int *arr, int pos, int z_value);
void	palette_gamma_red(int *arr, int pos, int z_value);

#endif