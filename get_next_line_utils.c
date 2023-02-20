/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:55:42 by mgeisler          #+#    #+#             */
/*   Updated: 2023/02/20 16:55:42 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_memchr(char *memb, int search, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (memb[i] == search)
			return (&memb[i]);
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
	{
		if (s2[j - 1] == '\n')
			break;
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}
