#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	*f(void *content)
{
	char	*temp;
	char	*rtn;

	temp = content;
	rtn = ft_strdup(" ");
	rtn[0] = temp[0] + 2;
	return (rtn);
}

int main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;

	t_list	**head;

	head =(t_list **)malloc(sizeof(t_list *));

	node1 = ft_lstnew(ft_strdup("1"));
	printf("value : %s\n", node1 -> content);
	printf("next : %p\n", NULL);
	printf("next : %p\n", node1 -> next);
	*head = node1;

	node2 = ft_lstnew(ft_strdup("2"));
	ft_lstadd_front(head, node2);
	printf("value : %s\n", node2 -> content);
	printf("next : %p\n", node1);
	printf("next : %p\n", node2 -> next);
	*head = node2;

	node3 = ft_lstnew(ft_strdup("3"));
	ft_lstadd_front(head, node3);
	printf("value : %s\n", node3 -> content);
	printf("next : %p\n", node2);
	printf("next : %p\n", node3 -> next);
	*head = node3;

	node4 = ft_lstnew(ft_strdup("4"));
	ft_lstadd_back(head, node4);
	printf("value : %s\n", node4 -> content);
	printf("next : %p\n", node4 -> next);

	*head = ft_lstmap(node3, f, free);
	while (*head)
	{
		printf("%s\n", (*head)->content);
		*head = ((*head)->next);
	}
    return (0);
}