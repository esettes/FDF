/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_props.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:21:37 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/25 04:27:08 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	set_mtrx_size(int x, int y)
{
	t_vec2 vertices;
	
	vertices.x = x;
	vertices.y = y;
	return (vertices);
}

void	set_pixel_size(t_fdf *fdf)
{
	fdf->mtrx.px_size.x = fdf->control.zoom * fdf->mtrx.vertices.x;
	fdf->mtrx.px_size.y = fdf->control.zoom * fdf->mtrx.vertices.y;
}

void	set_new_zoom(t_fdf *fdf)
{
	fdf->mtrx.px_size.x = fdf->control.zoom * (fdf->mtrx.vertices.x - 1);
	fdf->mtrx.px_size.y = fdf->control.zoom * (fdf->mtrx.vertices.y - 1);
	set_limits(&fdf->mtrx);
}

// void	set_new_zoom(t_fdf *fdf)
// {
// 	t_vec2	segm;

// 	segm.x = fdf->mtrx.vertices.x;
// 	segm.y = fdf->mtrx.vertices.y;
// 	fdf->mtrx.px_size.x = ((segm.y - 1) * fdf->control.zoom);
// 	fdf->mtrx.px_size.y = ((segm.x - 1) * fdf->control.zoom);
// 	set_new_limits(fdf);
// }

void	set_limits(t_mtrx *mtrx)
{
	mtrx->start.x = (IMG_CENTER_X - (mtrx->px_size.x / 2));
	mtrx->start.y = (IMG_CENTER_Y - (mtrx->px_size.y / 2));
	mtrx->end.x = mtrx->start.x + mtrx->px_size.x;
	mtrx->end.y = mtrx->start.y + mtrx->px_size.y;
}


/* limits functons when I try to draw vertices at the ssame time */
// void	set_limits(t_mtrx *mtrx)
// {
// 	mtrx->start.x = (IMG_CENTER_X - (mtrx->px_size.x / 2));
// 	mtrx->start.y = (IMG_CENTER_Y - (mtrx->px_size.y / 2));
// 	mtrx->end.x = mtrx->start.x + (mtrx->px_size.x / mtrx->vertices.x);
// 	mtrx->end.y = mtrx->start.y + (mtrx->px_size.y / mtrx->vertices.y);
// }

