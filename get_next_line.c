#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 		*buffer;
	char		*stock;
	int			i;
	static int	onum;

	onum = 0;
	i = 0;
	buffer = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while(buffer[i] != '\n')
	{
		onum = read(fd, buffer, BUFFER_SIZE);
		stock = ft_strjoin(buffer, stock);
		i++;
	}
	stock[onum] = '\0';
	free(buffer);
	return (stock);
}

/*int	main()
{
	int	i = 0;
	int	fd = open("texte.txt", O_RDONLY);
	
	while(i++ < 7)
		printf("%d, %s\n", i, get_next_line(fd));
	close(fd);
	return (0);
}*/
