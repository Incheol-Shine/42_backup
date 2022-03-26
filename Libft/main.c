#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	**head;

	head =(t_list **)malloc(sizeof(t_list *));

	node1 = ft_lstnew("3");
	printf("value : %s\n", node1 -> content);
	printf("next : %p\n", NULL);
	printf("next : %p\n", node1 -> next);
	*head = node1;

	node2 = ft_lstnew("2");
	ft_lstadd_front(head, node2);
	printf("value : %s\n", node2 -> content);
	printf("next : %p\n", node1);
	printf("next : %p\n", node2 -> next);
	*head = node2;

	node3 = ft_lstnew("1");
	ft_lstadd_front(head, node3);
	printf("value : %s\n", node3 -> content);
	printf("next : %p\n", node2);
	printf("next : %p\n", node3 -> next);
	*head = node3;

	while (*head)
	{
		printf("%s\n", (*head)->content);
		*head = ((*head)->next);
	}

	printf("count %d\n", ft_lstsize(node3));
	free(node1);
	free(node2);
	free(node3);
	
    return (0);
}