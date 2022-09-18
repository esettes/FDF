int		str_to_color(char *color);

void	palette_default(int *arr, int pos, int z_value)
{
	if (z_value >= 720)
		arr[pos] = str_to_color("deddcc");
	if (z_value < 720 && z_value >= 400)
		arr[pos] = str_to_color("c56930");
	if (z_value < 400 && z_value >= 200)
		arr[pos] = str_to_color("c66a31");
	if (z_value < 200 && z_value >= 90)
		arr[pos] = str_to_color("d77b34");
	if (z_value < 90 && z_value >= 50)
		arr[pos] = str_to_color("e79b34");
	if (z_value < 50 && z_value >= 35)
		arr[pos] = str_to_color("e9cab3");
	if (z_value < 35 && z_value >= 15)
		arr[pos] = str_to_color("b5baa6");
	if (z_value < 15 && z_value >= 0)
		arr[pos] = str_to_color("b2b8a5");
	if (z_value < 0 && z_value >= -5)
		arr[pos] = str_to_color("3babbf");
	if (z_value < -5 && z_value >= -20)
		arr[pos] = str_to_color("3aaaaf");
	if (z_value < -20 && z_value >= -70)
		arr[pos] = str_to_color("3ca9af");
	if (z_value < -70 && z_value >= -200)
		arr[pos] = str_to_color("3a98ae");
	if (z_value < -200)
		arr[pos] = str_to_color("3797ad");
}

void	palette_gamma(int *arr, int pos, int z_value)
{
	if (z_value >= 720)
		arr[pos] = str_to_color("800915");
	if (z_value < 720 && z_value >= 400)
		arr[pos] = str_to_color("cf8585");
	if (z_value < 400 && z_value >= 200)
		arr[pos] = str_to_color("de9050");
	if (z_value < 200 && z_value >= 90)
		arr[pos] = str_to_color("ccbb35");
	if (z_value < 90 && z_value >= 50)
		arr[pos] = str_to_color("70ee90");
	if (z_value < 50 && z_value >= 35)
		arr[pos] = str_to_color("40dcce");
	if (z_value < 35 && z_value >= 15)
		arr[pos] = str_to_color("158960");
	if (z_value < 15 && z_value >= 0)
		arr[pos] = str_to_color("104075");
	if (z_value < 0 && z_value >= -5)
		arr[pos] = str_to_color("265095");
	if (z_value < -5 && z_value >= -20)
		arr[pos] = str_to_color("505595");
	if (z_value < -20 && z_value >= -70)
		arr[pos] = str_to_color("3ca9af");
	if (z_value < -70 && z_value >= -200)
		arr[pos] = str_to_color("3a98ae");
	if (z_value < -200)
		arr[pos] = str_to_color("3797ad");
}

void	palette_test(int *arr, int pos, int z_value)
{
	if (z_value >= 0)
		arr[pos] = str_to_color("d773ca");
	else
		arr[pos] = str_to_color("b8ac94");
}