#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *s);
char		ft_memchr(char *memb, int search, size_t size);
char	*ft_buf(char *buffer);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);

#endif
