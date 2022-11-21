#include "get_next_line.h"
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
		ft_memcpy_gnl(str_st, buff, nbytes);
	}
	else
	{
		size = ft_strlen_eol(str_st, 0);
		tmp = ft_calloc_gnl(1, size + nbytes + 1);
		if (tmp == NULL)
			return (NULL);
		ft_memcpy_gnl(tmp, str_st, size);
		ft_memcpy_gnl(tmp + size, buff, nbytes + 1);
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
		if (str_st[eol] == '\n')
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

/* loop str_st by index searching \n instead with ft_strchr */

char	*read_buffersize(int fd, char *str_st)
{
	char	*buff;
	ssize_t		nbytes;
	nbytes = BUFFER_SIZE;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!ft_strchr_gnl(str_st, '\n') && nbytes == BUFFER_SIZE)
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
			str_st = concatenate_buff(str_st, buff, nbytes);
		}
		if (nbytes == 0)
		{
			free (str_st);
			free (buff);
			return (NULL);
		}
	}
	free (buff);
	return (str_st);
}

/* Create a struct with the static char and the eol size */

char	*get_next_line(int fd)
{
	static char	*str_st;
	char		*line;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1000)
		return (NULL);
	str_st = read_buffersize(fd, str_st);
	if (!str_st)
		return (NULL);
	line = get_line_break(str_st);
	return (line);
}

// int main(void)
// {
//     char    *line;
//     int     fd;
// 	int i = 0;
//     fd = open ("quijote.txt", O_RDONLY);
//     while (1)
//     {
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
//         //printf ("%s", line);
//         free (line);
//     }
// 	close(fd);
//     return (0);
// }