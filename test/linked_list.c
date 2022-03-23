#include <stdio.h>
#include <stdlib.h>

typedef struct s_NODE
{
    struct s_NODE *next;
    int data;
}   t_node;

int main()
{

    t_node *head = malloc(sizeof(t_node));

    t_node *node1 = malloc(sizeof(t_node));
    head->next = node1;
    node1->data = 10;

    t_node *node2 = malloc(sizeof(t_node));
    node1->next = node2;
    node2->data = 20;

    node2->next = NULL;

    t_node *curr = head->next;
    while (curr != NULL)
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }

    free(node2);
    free(node1);
    free(head);
    return 0;
}