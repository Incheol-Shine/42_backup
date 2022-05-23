#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// int main(void)
// {
// 	int		fd;
// 	char	*line;

// 	if (0 <= (fd = open( "./baudelaire.txt", O_RDONLY)))
// 	{
// 		int i = 0;
// 		printf("%d", i++);
// 		while (puts(line = get_next_line(fd)))
// 		{
// 			free(line);
// 			printf("%d ", i++);
// 		}
// 		close(fd)
// 	}
// 	else
// 	{
// 		printf("파일 열기에 실패했습니다.\n");
// 	}
// 	return (0);
// }

int main(void)
{
	ssize_t	fd1;
	ssize_t	fd2;
	char 	*line;

	fd1 = open( "./baudelaire.txt", O_RDONLY);
	fd2 = open( "./integer.txt", O_RDONLY);
	
	if ((0 <= fd1) && (0 <= fd2))
		for (int i=0; i<5; i++)
		{
			line = get_next_line(fd1);
			printf("%s\n--------------------------------------\n", line);
			free(line);
			line = get_next_line(fd2);
			printf("%s\n--------------------------------------\n", line);
			free(line);
		}
	return (0);
}

// int main(void)
// {
// 	t_list	**head;
// 	t_list	*new;
// 	ssize_t	fd;

// 	if (0 <= (fd = open( "./baudelaire.txt", O_RDONLY)))
// 	{
// 		head = (t_list **)malloc(sizeof(t_list *));
// 		if (!head)
// 			return (0);
// 		new = ft_lstnew(fd);
// 		if (!new)
// 			return (0);
// 		ft_lstadd_back(head, new);

// 		new = ft_lstnew(fd);
// 		if (!new)
// 			return (0);
// 		ft_lstadd_back(head, new);

// 		new = ft_lstnew(fd);
// 		if (!new)
// 			return (0);
// 		ft_lstadd_back(head, new);
// 		view(*head);

// 		// lstdel((*head)->next);
// 		lstdel(*head);
// 		view(*head);

// 		cpydel(line, head, size)
// 	}
// 	return (0);
// }

