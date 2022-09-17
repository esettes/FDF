#include "fdf.h"

void    get_z_points(t_map *m, char *str, int pos)
{
    char	**ch_aux;
    int		*z_point;
    t_iter  iter;
    t_iter  aux;

    iter.i = 0;
    iter.j = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    z_point = malloc(sizeof(int) * iter.j + 1);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        iter.i = ft_atoi(ch_aux[iter.j]);
		*(z_point + iter.j) = iter.i;
		iter.j++;
    }
    m->map[pos] = z_point;
    if (ch_aux)
        free (ch_aux);
    free (str);
}

void	get_color_points(t_map *m, char *str, int pos)
{
    char	**ch_aux;
    char    *extract;
    int     i_color;
    t_iter  iter;
    int     *int_color;

    iter.i = 0;
    iter.j = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    int_color = malloc(sizeof(int) * iter.j + 1);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        //extract = ft_strnstr_after(ch_aux[iter.j], "x", 5);
        extract = ft_strchr(ch_aux[iter.j], 'x');
        // si la extraccion es distinta de lo que ya hay en la cadena entonces calcular, sino continuar
        if (extract)// && extract != "")
        {
            extract++;
            i_color = str_to_color(extract);
            *(int_color + iter.j) = i_color;
            extract = ""; 
        }
        else
          *(int_color + iter.j) = 255;
		iter.j++;
    }
    m->colors[pos] = int_color;
    if (ch_aux)
        free (ch_aux);
    free (str);
}

void	obtain_z_and_color(t_map *m, char *str, int pos)
{
    char	**ch_aux;
    char    *extract;
    int     i_color;
    int		*int_mtrx;
    t_iter  iter;
    t_iter  aux;
    int     *int_color;

    iter.i = 0;
    iter.j = 0;
    ch_aux = ft_split(str, ' ');
    while (ch_aux[iter.j])
		iter.j++;
    int_mtrx = malloc(sizeof(int) * iter.j + 1);
    int_color = malloc(sizeof(int) * iter.j + 1);
    iter.j = 0;
	while (ch_aux[iter.j])
    {
        extract = ft_strchr(ch_aux[iter.j], 'x');
        iter.i = ft_atoi(ch_aux[iter.j]);
		*(int_mtrx + iter.j) = iter.i;
        if (extract)// && extract != "")
        {
            extract++;
            i_color = str_to_color(extract);
            *(int_color + iter.j) = i_color;
            extract = ""; 
        }
        else
        {
            if (iter.i >= 720)
                *(int_color + iter.j) = str_to_color("deddcc");
            if (iter.i < 720 && iter.i >= 400)
                *(int_color + iter.j) = str_to_color("c56930");
            if (iter.i < 400 && iter.i >= 200)
                *(int_color + iter.j) = str_to_color("c66a31");
            if (iter.i < 200 && iter.i >= 90)
                *(int_color + iter.j) = str_to_color("d77b34");
            if (iter.i < 90 && iter.i >= 50)
                *(int_color + iter.j) = str_to_color("e79b34");
            if (iter.i < 50 && iter.i >= 35)
                *(int_color + iter.j) = str_to_color("e9cab3");
            if (iter.i < 35 && iter.i >= 15)
                *(int_color + iter.j) = str_to_color("b5baa6");
            if (iter.i < 15 && iter.i >= 0)
                *(int_color + iter.j) = str_to_color("b2b8a5");
            if (iter.i < 0 && iter.i >= -5)
                *(int_color + iter.j) = str_to_color("3babbf"); //31a9ac
            if (iter.i < -5 && iter.i >= -20)
                *(int_color + iter.j) = str_to_color("3aaaaf");
            if (iter.i < -20 && iter.i >= -70)
                *(int_color + iter.j) = str_to_color("3ca9af");//3bb143
            if (iter.i < -70 && iter.i >= -200)
                *(int_color + iter.j) = str_to_color("3a98ae");
            if (iter.i < -200)// && iter.i >= -30)
                *(int_color + iter.j) = str_to_color("3797ad");
            //if (iter.i == 0)
             //   *(int_color + iter.j) = str_to_color("29ab87");
        }
		iter.j++;
    }
    m->colors[pos] = int_color;
    m->map[pos] = int_mtrx;
    //free (int_mtrx);
    if (ch_aux)
        free (ch_aux);
    free (str);
}

// funcion que detecta altura de la z y devuelve un color acorde
//unsigned int    color_for_z(int z)