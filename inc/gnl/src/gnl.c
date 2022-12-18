/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 00:23:35 by iostancu          #+#    #+#             */
/*   Updated: 2022/12/19 00:41:13 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <sys/types.h>

char	*concatenate_buff(char *str_st, char *buff, size_t nbytes)
{
	char	*tmp;
	size_t	size;

	if (str_st == NULL)
	{
		str_st = ft_calloc_gnl(1, nbytes + 1);
		if (str_st == NULL)
			return (NULL);
		ft_memmove_gnl(str_st, buff, nbytes);
	}
	else
	{
		size = ft_strlen_eol(str_st, 0);
		tmp = ft_calloc_gnl(1, size + nbytes + 1);
		if (tmp == NULL)
			return (NULL);
		ft_memmove_gnl(tmp, str_st, size);
		ft_memmove_gnl(tmp + size, buff, nbytes + 1);
		free(str_st);
		str_st = tmp;
	}
	return (str_st);
}

char	*get_line_break(char *str_st)
{
	size_t	eol;
	char	*line;
	size_t	str_st_len;
	size_t	line_len;

	eol = 0;
	line = malloc(sizeof(char) * (ft_strlen_eol(str_st, TRUE) + 1));
	while (str_st[eol])
	{
		line[eol] = str_st[eol];
		if (str_st[eol] == '\n' || str_st[eol + 1] == '\0')
		{
			line[eol + 1] = '\0';
			line_len = ft_strlen_eol(line, 0);
			str_st_len = ft_strlen_eol(str_st, 0);
			ft_memmove_gnl(str_st, str_st + eol + 1, str_st_len - line_len);
			*(str_st + str_st_len - line_len) = '\0';
			return (line);
		}
		eol++;
	}
	return (line);
}

char	*read_buffersize(int fd, char *str_st, char *buff, ssize_t nbytes)
{
	nbytes = BUFFER_SIZE;
	while (!ft_strchr_gnl(str_st, '\n') && nbytes == BUFFER_SIZE)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes <= -1)
		{
			free (buff);
			free (str_st);
			return (NULL);
		}
		if (nbytes == 0)
		{
			if (str_st[0] != '\0')
			{
				free (buff);
				return (str_st);
			}
			free (str_st);
			return (NULL);
		}
		buff[nbytes] = '\0';
		str_st = concatenate_buff(str_st, buff, nbytes);
	}
	free (buff);
	return (str_st);
}

void	init_data(t_data *data)
{
	if (data->str_st == NULL)
		data->str_st = ft_calloc_gnl(1, BUFFER_SIZE + 1);
	data->nbytes = BUFFER_SIZE;
	data->buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
}

char	*get_next_line(int fd)
{
	static t_data	data;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1000)
		return (NULL);
	init_data(&data);
	data.str_st = read_buffersize(fd, data.str_st, data.buff, data.nbytes);
	if (!data.str_st)
	{
		if (data.buff)
			free (data.buff);
		return (NULL);
	}
	line = get_line_break(data.str_st);
	if (!line)
		free (data.str_st);
	return (line);
}
