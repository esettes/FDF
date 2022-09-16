/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:12:56 by iostancu          #+#    #+#             */
/*   Updated: 2022/07/08 18:38:18 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*get_next_next(char *str)
{
	size_t	eol;
	size_t	str_len;
	size_t	i;
	char	*line;

	eol = ft_strlen_eol(str, TRUE);
	if (!str[eol])
	{
		free(str);
		return (NULL);
	}
	str_len = ft_strlen_eol(str, FALSE);
	line = (char *)malloc(sizeof(char) * (str_len - eol + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (eol + i < str_len)
	{
		line[i] = str[eol + i];
		i++;
	}
	line[i] = '\0';
	free (str);
	return (line);
}

char	*get_line(char *str)
{
	size_t	eol;
	char	*line;

	eol = 0;
	line = (char *)malloc(sizeof(char) * (ft_strlen_eol(str, FALSE) + 1));
	if (str[0] == '\n')
	{
		line[0] = '\n';
		eol++;
	}
	while (str[eol - 1] != '\n' && str[eol])
	{
		line[eol] = str[eol];
		eol++;
	}
	line[eol] = '\0';
	return (line);
}

char	*read_fd(int fd, char *str)
{
	char	*buff;
	int		nbytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nbytes = BUFFER_SIZE;
	while (!ft_strchr_gnl(str, '\n') && nbytes == BUFFER_SIZE)
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (buff);
			return (NULL);
		}
		if (nbytes != 0)
		{
			buff[nbytes] = '\0';
			if (!str)
				str = ft_strdup_gnl(buff);
			else
				str = ft_strjoin_gnl(str, buff);
		}
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str_st[OPEN_MAX];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	str_st[fd] = read_fd(fd, str_st[fd]);
	if (!str_st[fd])
		return (NULL);
	line = get_line(str_st[fd]);
	str_st[fd] = get_next_next(str_st[fd]);
	return (line);
}
