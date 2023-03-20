/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeisler <mgeisler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:01:31 by mgeisler          #+#    #+#             */
/*   Updated: 2023/02/25 18:01:31 by mgeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_memchr2(char *memb, int search, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		if (memb[i] == search)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_buf(char *buffer)
{
	int	i;
	int	j;

	j = 0;
	i = ft_memchr2(buffer, '\n', ft_strlen(buffer)) + 1;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j++] = '\0';
	while (buffer[j])
		buffer[j++] = '\0';
	return (buffer);
}

void	ft_bzero(void *s, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t ecount, size_t esize)
{
	void	*str;

	str = malloc(ecount * esize);
	if (ecount == 0 || esize == 0)
		return (str);
	if (str == 0)
		return (0);
	ft_bzero(str, ecount * esize);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*stock;
	int				onum;

	onum = BUFFER_SIZE;
	if (read(fd, 0, 0) < 0)
		return (0);
	stock = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!stock)
		return (0);
	while (onum == BUFFER_SIZE)
	{
		onum = read(fd, buffer, BUFFER_SIZE);
		if (onum == -1)
		{
			free(stock);
			stock = NULL;
			return (NULL);
		}
		buffer[onum] = '\0';
		if (ft_memchr(buffer, '\n', ft_strlen(buffer)))
		{
			stock = ft_strjoin(stock, buffer);
			if (buffer[0] != '\0')
				ft_buf(buffer);
			return (stock);
		}
		stock = ft_strjoin(stock, buffer);
		if (stock[0] == '\0')
		{
			free(stock);
			stock = NULL;
			return (0);
		}
	}
	return (stock);
}

// int	main()
// {
// 	int	fd = open("test.txt", O_RDONLY);

// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
