#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/stat.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif
# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	char	*str_st;
	char	*buff;
	ssize_t	nbytes;
}	t_data;

char	*get_next_line(int fd);
size_t	ft_strlen_eol(const char *s, int lineLenght);
int		ft_strchr_gnl(const char *s, int c);
void	*ft_memmove_gnl(void *dst, const void *src, size_t len);
char	*ft_calloc_gnl(size_t count, size_t size);

#endif