/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:12:41 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/09 23:09:40 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "MLX42.h"
# include <math.h>

/*
 * @param[in] x float
 * @param[in] y float
 */
typedef struct s_vec2
{
	float	x;
	float	y;
}				t_vec2;
/*
 * @param[in] z int
 * @param[in] z1 int
 */
typedef struct s_depth
{
	int	z;
	int	z1;
}				t_depth;
/*
 * @param[in] i int
 * @param[in] j int
 */
typedef struct s_iter
{
	int	i;
	int	j;
}				t_iter;
/*
 * @param[in] r unsigned int
 * @param[in] g unint
 * @param[in] b unint
 * @param[in] a unint
 */
typedef struct s_rgba
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	a;
}				t_rgba;
/*
 * @param[in] height float
 * @param[in] zoom float
 * @param[in] perspective size_t
 * @param[in] horiz int
 * @param[in] vert int
 */
typedef	struct s_controls
{
	float	height;
	float	rot_angle;
	float	zoom;
	size_t	perspective;
	int		horiz;
	int		vert;
}				t_controls;
/**
 * Save all the values ​​necessary for the mesh construction.
 * 
 * @param[in] map Mesh integer array of 'z' points.
 * @param[in] z Mesh's depth.
 * @param[in] zoom Value that sets the distance between adjoining vertices.
 * @param[in] vertices number of vertices in width(x) and height(y)
 * @param[in] px_size Pixel size of width(x) and height(y).
 * @param[in] start Coord where to start to draw in the img.
 * @param[in] end Coord where to finish to draw in the img.
 */
typedef struct s_map
{
	int			**map;
	int			**colors;
	int			z;
	float		zoom;
	t_vec2		vertices;
	t_vec2		px_size;
	t_vec2		start;
	t_vec2		end;
	t_vec2		offset;
}				t_map;
/**
 * Main struct of the program, used to store structs initializations
 * required by MLX and program variables. Simplifies the use of the mesh data.
 * 
 * @param mlx Struct required by mlx.
 * @param map Structure for the mesh data.
 * @param img Struct required by mlx.
 */
typedef struct s_fdf
{
	mlx_t		*mlx;
	t_map		map;
	t_controls	control;
	mlx_image_t	*img;		// Has position
	int			fd;
	char	**readed_fd;
}				t_fdf;

#endif