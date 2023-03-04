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

char	*ft_buf(char *buffer)
{
	int	i;
	int j;

	j = 0;
	i = ft_memchr(buffer, '\n', ft_strlen(buffer)) + 1;
	while (buffer[i - 1])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char 	buffer[BUFFER_SIZE + 1];
	char			*stock;
	char			*stack;
	int				onum;

	stack = 0;
	onum = BUFFER_SIZE;
	stock = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!stock)
		return (0);
	ft_strcpy(stock, buffer);
	while (onum == BUFFER_SIZE)
	{
		onum = read(fd, buffer, BUFFER_SIZE);
		buffer[onum] = '\0';
		if (onum < 0)
		{
			free(stock);
			return (NULL);
		}
		if (ft_memchr(buffer, '\n', ft_strlen(buffer)))
		{
			stock = ft_strjoin(stock, buffer);
			stack = ft_strdup(stock);
			if (buffer[0] != '\0')
				ft_buf(buffer);
			return (stack);
		}
		if (buffer[0] == '\0' && !stack)
		{
			free(stock);
			return (NULL);
		}
		stock = ft_strjoin(stock, buffer);
	}
	stack = ft_strdup(stock);
	return (stack);
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
