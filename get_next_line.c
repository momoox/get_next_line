#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 			buffer[BUFFER_SIZE + 1];
	static char		*stock;
	int				onum;
	int				i;

	onum = BUFFER_SIZE;
	i = 0;
	//stock ecrase ce qui a etait deja copié dessus
	while (onum == BUFFER_SIZE)
	{
		onum = read(fd, buffer, BUFFER_SIZE);
		stock[i] = *ft_strjoin(buffer);
		i++;
	}
	stock[i] = '\0';
	return (stock);
}

int	main()
{
	int	fd = open("texte.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
