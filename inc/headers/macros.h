/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:35:22 by iostancu          #+#    #+#             */
/*   Updated: 2022/09/12 19:57:54 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_FDF_H
# define MACROS_FDF_H

# define WIDTH		1350
# define HEIGHT		720
# define IMG_AUMENT		2
# define X_ORIGIN_OFF	( WIDTH / 2 )
# define Y_ORIGIN_OFF	( HEIGHT / 2 )
# define IMG_CENTER_X	((WIDTH * IMG_AUMENT) / 2)
# define IMG_CENTER_Y	((HEIGHT * IMG_AUMENT) / 2)
# define MAX_HEIGHT     (HEIGHT * IMG_AUMENT - 100)
# define MAX_WIDTH      (WIDTH * IMG_AUMENT - 100)
# define ISOMETRIC		0
# define TOP_VIEW		1
# define ADDIT_STEPS    3

#endif