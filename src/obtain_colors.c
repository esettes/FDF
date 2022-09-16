#include "fdf.h"

void    get_z_points(t_mtrx *m, char *str, int pos)
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
    m->mtrx[pos] = z_point;
    if (ch_aux)
        free (ch_aux);
    free (str);
}

void	get_color_points(t_mtrx *m, char *str, int pos)
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

void	obtain_z_and_color(t_mtrx *m, char *str, int pos)
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
            if (iter.i >= 600)
                *(int_color + iter.j) = str_to_color("dddccc");
            if (iter.i < 600 && iter.i >= 450)
                *(int_color + iter.j) = str_to_color("c46829");
            if (iter.i < 450 && iter.i >= 220)
                *(int_color + iter.j) = str_to_color("c56930");
            if (iter.i < 220 && iter.i >= 130)
                *(int_color + iter.j) = str_to_color("d67a33");
            if (iter.i < 130 && iter.i >= 50)
                *(int_color + iter.j) = str_to_color("e69a33");
            if (iter.i < 50 && iter.i >= 35)
                *(int_color + iter.j) = str_to_color("e7cab1");
            if (iter.i < 35 && iter.i >= 15)
                *(int_color + iter.j) = str_to_color("b5b9a4");
            if (iter.i < 15 && iter.i >= 0)
                *(int_color + iter.j) = str_to_color("b2b7a4");
            if (iter.i < 0 && iter.i >= -40)
                *(int_color + iter.j) = str_to_color("31baad");//3bb143
            if (iter.i < -40)// && iter.i >= -30)
                *(int_color + iter.j) = str_to_color("3997ad");
            //if (iter.i == 0)
             //   *(int_color + iter.j) = str_to_color("29ab87");
        }
		iter.j++;
    }
    m->colors[pos] = int_color;
    m->mtrx[pos] = int_mtrx;
    //free (int_mtrx);
    if (ch_aux)
        free (ch_aux);
    free (str);
}

// funcion que detecta altura de la z y devuelve un color acorde
//unsigned int    color_for_z(int z)