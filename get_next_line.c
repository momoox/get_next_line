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
	int				onum;

	onum = BUFFER_SIZE;
	stock = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ft_strcpy(stock, buffer);
	while (onum == BUFFER_SIZE)
	{
		onum = read(fd, buffer, BUFFER_SIZE);
		buffer[onum] = '\0';
		if (ft_memchr(buffer, '\n', ft_strlen(buffer)))
		{
			stock = ft_strjoin(stock, buffer);
			if (buffer[0] != '\0')
				ft_buf(buffer);
			return (stock);
		}
		stock = ft_strjoin(stock, buffer);
	}
	stock[ft_strlen(stock) + 1] = '\0';
	return (stock);
}

// int	main()
// {
// 	int	fd = open("text2.txt", O_RDONLY);

// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
