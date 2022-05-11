#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int		fd;
	char	*line;

	if (0 <= (fd = open( "./baudelaire.txt", O_RDONLY)))
	{
		int i = 0;
		printf("%d", i++);
		while (puts(line = get_next_line(fd)))
		{
			free(line);
			printf("%d ", i++);
		}
		close(fd)
	}
	else
	{
		printf("파일 열기에 실패했습니다.\n");
	}
	return (0);
}