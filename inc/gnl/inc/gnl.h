/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iostancu <iostancu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:19:28 by iostancu          #+#    #+#             */
/*   Updated: 2022/06/29 18:27:10 by iostancu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/stat.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# define TRUE 1
# define FALSE 0
# ifndef OPEN_MAX
# define OPEN_MAX 10
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_eol(const char *s, int lineLenght);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_gnl(const char *s, int c);
char	*ft_strdup_gnl(const char *s1);
char	*read_fd(int fd, char *str);

#endif
