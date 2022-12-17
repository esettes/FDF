/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palettes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:53:06 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/16 23:00:05 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		hex_to_color(char *color);

void	palette_default(int *arr, int pos, int z_value)
{
	arr[pos] = z_value;
}

void	palette_terrain(int *arr, int pos, int z_value)
{
	if (z_value >= 720)
		arr[pos] = hex_to_color("deddcc");
	if (z_value < 720 && z_value >= 400)
		arr[pos] = hex_to_color("c56930");
	if (z_value < 400 && z_value >= 200)
		arr[pos] = hex_to_color("c66a31");
	if (z_value < 200 && z_value >= 90)
		arr[pos] = hex_to_color("d77b34");
	if (z_value < 90 && z_value >= 50)
		arr[pos] = hex_to_color("e79b34");
	if (z_value < 50 && z_value >= 35)
		arr[pos] = hex_to_color("e9cab3");
	if (z_value < 35 && z_value >= 15)
		arr[pos] = hex_to_color("b5baa6");
	if (z_value < 15 && z_value >= 0)
		arr[pos] = hex_to_color("b2b8a5");
	if (z_value < 0 && z_value >= -5)
		arr[pos] = hex_to_color("3babbf");
	if (z_value < -5 && z_value >= -20)
		arr[pos] = hex_to_color("3aaaaf");
	if (z_value < -20 && z_value >= -70)
		arr[pos] = hex_to_color("3ca9af");
	if (z_value < -70 && z_value >= -200)
		arr[pos] = hex_to_color("3a98ae");
	if (z_value < -200)
		arr[pos] = hex_to_color("3797ad");
}

void	palette_gamma(int *arr, int pos, int z_value)
{
	if (z_value >= 720)
		arr[pos] = hex_to_color("ac7456");
	if (z_value < 720 && z_value >= 400)
		arr[pos] = hex_to_color("bfabcc");
	if (z_value < 400 && z_value >= 200)
		arr[pos] = hex_to_color("ddab41");
	if (z_value < 200 && z_value >= 90)
		arr[pos] = hex_to_color("decd51");
	if (z_value < 90 && z_value >= 0)
		arr[pos] = hex_to_color("aced99");
	if (z_value == 0)
		arr[pos] = hex_to_color("ac74f9");
	if (z_value < 0 && z_value >= -80)
		arr[pos] = hex_to_color("40cdbf");
	if (z_value < -80 && z_value >= -170)
		arr[pos] = hex_to_color("189995");
	if (z_value < -170 && z_value >= -250)
		arr[pos] = hex_to_color("555999");
	if (z_value < -250 && z_value >= -320)
		arr[pos] = hex_to_color("60699b");
	if (z_value < -320 && z_value >= -400)
		arr[pos] = hex_to_color("8879be");
	if (z_value < -400 && z_value >= -460)
		arr[pos] = hex_to_color("ac74f9");
	if (z_value < -460)
		arr[pos] = hex_to_color("997498");
}

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
