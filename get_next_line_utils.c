#include "get_next_line.h"

size_t  ft_strlen(char  *s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = (char)s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = (char)s2[j++];
	str[i] = '\0';
    free(str);
	return (str);
}
