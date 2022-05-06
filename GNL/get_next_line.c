# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

#define  BUFF_SIZE   3000

char	*get_next_line(int fd)
{

}

int main(void)
{
	char   buff[BUFF_SIZE];
	int    fd;

	if (0 < (fd = open( "./baudelaire.txt", O_RDONLY)))
	{
		while (puts(get_next_line(fd)))
    	close(fd);
	}
	else
	{
		printf("파일 열기에 실패했습니다.\n");
	}
	return (0);
}