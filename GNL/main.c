#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// int main(void)
// {
// 	ssize_t	fd1;
// 	ssize_t	fd2;
// 	char 	*line;

// 	fd1 = open( "./baudelaire.txt", O_RDONLY);
// 	fd2 = open( "./integer.txt", O_RDONLY);
// 	if (0 <= fd1 && 0 <= fd2)
// 		for (int i=0; i<2; i++)
// 		{
// 			line = get_next_line(fd2);
// 			printf("%s", line);
// 			free(line);
// 			// line = get_next_line(fd2);
// 			// printf("--------------------------------------\n%s\n", line);
// 			// free(line);
// 			// line = get_next_line(fd1);
// 			// printf("--------------------------------------\n%s\n", line);
// 			// free(line);
// 		}
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }


int	main(void)
{
	ssize_t	fd[4];

	fd[0] = open("./41_with_nl", O_RDWR);
	/* 1 */ printf("-------------\n%s\n", get_next_line(1000));
	/* 2 */ printf("-------------\n%s\n", get_next_line(fd[0]));

	fd[1] = open("./42_with_nl", O_RDWR);
	/* 3 */ printf("-------------\n%s\n", get_next_line(1001));
	/* 4 */ printf("-------------\n%s\n", get_next_line(fd[1]));

	fd[2] = open("./43_with_nl", O_RDWR);
	/* 5 */ printf("-------------\n%s\n", get_next_line(1002));
	/* 6 */ printf("-------------\n%s\n", get_next_line(fd[2]));

	/* 7 */ printf("-------------\n%s\n", get_next_line(1003));
	/* 8 */ printf("-------------\n%s\n", get_next_line(fd[0]));

	/* 9 */ printf("-------------\n%s\n", get_next_line(1004));
	/* 10 */ printf("-------------\n%s\n", get_next_line(fd[1]));

	/* 11 */ printf("-------------\n%s\n", get_next_line(1005));
	/* 12 */ printf("-------------\n%s\n", get_next_line(fd[2]));

	/* 13 */ printf("-------------\n%s\n", get_next_line(fd[0]));
	/* 14 */ printf("-------------\n%s\n", get_next_line(fd[1]));
	/* 15 */ printf("-------------\n%s\n", get_next_line(fd[2]));

	fd[3] = open("./nl", O_RDWR);
	/* 16 */ printf("-------------\n%s\n", get_next_line(1006));
	/* 17 */ printf("-------------\n%s\n", get_next_line(fd[3]));
	/* 18 */ printf("-------------\n%s\n", get_next_line(1007));
	/* 19 */ printf("-------------\n%s\n", get_next_line(fd[3]));
	return (0);
}