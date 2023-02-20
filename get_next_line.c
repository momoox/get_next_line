#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 			buffer[BUFFER_SIZE + 1];
	static char		*stock;
	char			*stack;
	int				onum;

	onum = BUFFER_SIZE;
	stack = NULL;
	stock = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (onum == BUFFER_SIZE)
	{
		onum = read(fd, buffer, BUFFER_SIZE);
		if (ft_memchr(buffer, '\n', ft_strlen(buffer)))
		{
			stock = ft_strjoin(stock, buffer);
			stack[ft_strlen(stock)] = stock[ft_strlen(stock)];
			return (stack);
		}
		stock = ft_strjoin(stock, buffer);
	}
	stock[ft_strlen(stock) + 1] = '\0';
	stack[ft_strlen(stock)] = stock[ft_strlen(stock)];
	return (stack);
}

int	main()
{
	int	fd = open("text2.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
