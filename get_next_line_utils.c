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

char	*ft_strjoin(char *s1)
{
	char		*str;
	int			i;
	int			k;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
		str[k++] = s1[i++];
	str[k] = '\0';
	return (str);
}
