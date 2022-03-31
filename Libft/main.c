#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	f(void *content)
{
	char 	*temp;
	temp = content;
	temp[0] = '0';
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
	// while (*head)
	// {
	// 	printf("%s\n", (*head)->content);
	// 	*head = ((*head)->next);
	// }
	ft_lstiter(node3, f);
	printf("*head: %p\n", *head);
	printf("*head->content: %s\n", (*head)->content);
	printf("node3: %s\n", node3->content);
	printf("node3->next: %s\n", node3->next->content);
	printf("node2: %s\n", node2->content);
	printf("node2->next: %s\n", node2->next->content);
	printf("node1: %s\n", node1->content);
	printf("node1->next: %s\n", node1->next->content);
	printf("node4: %s\n", node4->content);
	printf("node4->next: %s\n", node4->next->content);
	// free(node1);
	// free(node2);
	// free(node3);
	// free(node4);
	
    return (0);
}