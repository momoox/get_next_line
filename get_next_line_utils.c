#include "get_next_line.h"

int	ft_strlen(char  *s)
{
    int i;

    i = 0;
	if (!s)
		return (0);
    while(s[i])
        i++;
    return (i);
}

void	*ft_memchr(const void *memb, int search, size_t size)
{
	size_t			i;
	unsigned char	srch;
	unsigned char	*str;

	i = 0;
	srch = (unsigned char) search;
	str = (unsigned char *) memb;
	while (i < size)
	{
		if (str[i] == srch)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
