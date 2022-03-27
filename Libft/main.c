/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: incshin <incshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:31:04 by incshin           #+#    #+#             */
/*   Updated: 2022/03/27 15:31:04 by incshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	del(void *node)
{
	free(node);
}

int main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*node4;
	t_list	**head;

	head =(t_list **)malloc(sizeof(t_list *));

	node1 = ft_lstnew("1");
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

	node3 = ft_lstnew("3");
	ft_lstadd_front(head, node3);
	printf("value : %s\n", node3 -> content);
	printf("next : %p\n", node2);
	printf("next : %p\n", node3 -> next);
	*head = node3;

	node4 = ft_lstnew("4");
	ft_lstadd_back(head, node4);
	printf("value : %s\n", node4 -> content);
	printf("next : %p\n", node4 -> next);
	while (*head)
	{
		printf("%s\n", (*head)->content);
		*head = ((*head)->next);
	}

	ft_lstdelone(node2, &del);

	free(node1);
	free(node2);
	free(node3);
	free(node4);
	
    return (0);
