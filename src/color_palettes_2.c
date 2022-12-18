/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palettes_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:00:13 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/19 00:00:25 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		hex_to_color(char *color);

void	palette_test(int *arr, int pos, int z_value)
{
	if (z_value >= 0)
		arr[pos] = hex_to_color("d773ca");
	else
		arr[pos] = hex_to_color("b8ac94");
}

void	palette_gamma_red(int *arr, int pos, int z_value)
{
	if (z_value > 13)
		arr[pos] = hex_to_color("aca951");
	if (z_value <= 13 && z_value >= 10)
		arr[pos] = hex_to_color("ab9553");
	if (z_value < 10 && z_value >= 7)
		arr[pos] = hex_to_color("aa7543");
	if (z_value < 7 && z_value >= 4)
		arr[pos] = hex_to_color("825536");
	if (z_value < 4)
		arr[pos] = hex_to_color("856040");
}
