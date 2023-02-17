#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 			buffer[BUFFER_SIZE + 1];
	static char		*stock;
	int				onum;
	int				i;

	onum = BUFFER_SIZE;
	i = 0;
	stock = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (onum == BUFFER_SIZE)
	{
		onum = read(fd, buffer, BUFFER_SIZE);
		buffer[onum] = '\0';
		if (ft_memchr(buffer, '\n', ft_strlen(buffer)))
			break;
		stock = ft_strjoin(stock, buffer);
		i++;
	}
	stock[i] = '\0';
	return (stock);
}

int	main()
{
	int	fd = open("text2.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
