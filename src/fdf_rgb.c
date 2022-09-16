/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 23:27:02 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/28 19:44:45 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int menu_rgb(int value)
{
	if (value == 0)
		return (MENUDGREY);
	if (value == 1)
		return (MENUMGREY);
	else
		return (MENUMLGREY);
}

int	rgba(int value)
{
	if (value == 0)
		return (BLU_CB);
	if (value == 1)
		return (BLUE);
	if (value == 2)
		return (BLU_CB);
	if (value == 3)
		return (BLU_AD);
	if (value == 4)
		return (CYBRED);
	if (value == 5)
		return (NEOLGREEN);
	else
		return (NEOWITHE);
}
