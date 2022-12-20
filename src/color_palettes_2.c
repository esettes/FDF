/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palettes_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:00:13 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/20 16:40:21 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		hex_to_color(char *color);
void	pallete_gamma_random_2(int *arr, int pos, int z_value);

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
		arr[pos] = hex_to_color("ab7153");
	if (z_value < 10 && z_value >= 7)
		arr[pos] = hex_to_color("aa6543");
	if (z_value < 7 && z_value >= 4)
		arr[pos] = hex_to_color("825536");
	if (z_value < 4 && z_value >= -5)
		arr[pos] = hex_to_color("965035");
	if (z_value < -5)
		arr[pos] = hex_to_color("853535");
}

void	palette_gamma_random(int *arr, int pos, int z_value)
{
	if (z_value > 100)
		arr[pos] = hex_to_color("7799a7");
	if (z_value <= 100 && z_value >= 50)
		arr[pos] = hex_to_color("b8ba99");
	if (z_value < 50 && z_value >= 15)
		arr[pos] = hex_to_color("b8ba5a");
	if (z_value < 15 && z_value >= 0)
		arr[pos] = hex_to_color("b8ab94");
	if (z_value < -15 && z_value >= -60)
		arr[pos] = hex_to_color("b8ac94");
	if (z_value < -60 && z_value >= -90)
		arr[pos] = hex_to_color("b5ab90");
	if (z_value < -90 && z_value >= -140)
		arr[pos] = hex_to_color("b3aa86");
	if (z_value < -140 && z_value >= -170)
		arr[pos] = hex_to_color("a09783");
	if (z_value < -170 && z_value >= -210)
		arr[pos] = hex_to_color("959282");
	if (z_value < -210 && z_value >= -240)
		arr[pos] = hex_to_color("918381");
	if (z_value < -240 && z_value >= -280)
		arr[pos] = hex_to_color("897882");
	pallete_gamma_random_2(arr, pos, z_value);
}

void	pallete_gamma_random_2(int *arr, int pos, int z_value)
{
	if (z_value < -280 && z_value >= -310)
		arr[pos] = hex_to_color("887780");
	if (z_value < -310 && z_value >= -460)
		arr[pos] = hex_to_color("877678");
	if (z_value < -460 && z_value >= -510)
		arr[pos] = hex_to_color("857576");
	if (z_value < -510 && z_value >= -560)
		arr[pos] = hex_to_color("847474");
	if (z_value < -560 && z_value >= -610)
		arr[pos] = hex_to_color("837272");
	if (z_value < -610)
		arr[pos] = hex_to_color("827070");
}
