#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
// #include "get_next_line_bonus.h"

void	readfile(char *file, int print)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (print)
			printf("%s", line);
		free(line);
	}
	line = get_next_line(fd);
	if (line)
	{
		if (print)
			printf("%s", line);
		free(line);
	}
	close(fd);
}

int	main(void)
{
	int	ex = 0;
//	readfile("file.txt", !ex);
	readfile("baudelaire.txt", !ex);
     sleep(100);
	return (1);
}
