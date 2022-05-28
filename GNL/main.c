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
	/* 1 */ printf("------1------\n%s\n", get_next_line(1000));
	/* 2 */ printf("------2------\n%s\n", get_next_line(fd[0]));

	fd[1] = open("./42_with_nl", O_RDWR);
	/* 3 */ printf("------3------\n%s\n", get_next_line(1001));
	/* 4 */ printf("------4------\n%s\n", get_next_line(fd[1]));

	fd[2] = open("./43_with_nl", O_RDWR);
	/* 5 */ printf("------5------\n%s\n", get_next_line(1002));
	/* 6 */ printf("------6------\n%s\n", get_next_line(fd[2]));

	/* 7 */ printf("------7------\n%s\n", get_next_line(1003));
	/* 8 */ printf("------8------\n%s\n", get_next_line(fd[0]));

	/* 9 */ printf("------9------\n%s\n", get_next_line(1004));
	/* 10 */ printf("-----10------\n%s\n", get_next_line(fd[1]));

	/* 11 */ printf("-----11------\n%s\n", get_next_line(1005));
	/* 12 */ printf("-----12------\n%s\n", get_next_line(fd[2]));

	/* 13 */ printf("-----13------\n%s\n", get_next_line(fd[0]));
	/* 14 */ printf("-----14------\n%s\n", get_next_line(fd[1]));
	/* 15 */ printf("-----15------\n%s\n", get_next_line(fd[2]));

	fd[3] = open("./nl", O_RDWR);
	/* 16 */ printf("-----16------\n%s\n", get_next_line(1006));
	/* 17 */ printf("-----17------\n%s\n", get_next_line(fd[3]));
	/* 18 */ printf("-----18------\n%s\n", get_next_line(1007));
	/* 19 */ printf("-----19------\n%s\n", get_next_line(fd[3]));

	system("leaks a.out > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");


	return (0);
}