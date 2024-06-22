// delete a node with given index...
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *delete_at_anyindex(struct Node *head, int index)
{
    struct Node *ptr = head;

    if (index == 0)
    {
        head = head->next;
        free(ptr);
        return head;
    }

    for (int i = 0; i < index - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL || ptr->next == NULL)
    {
        return head;
    }

    struct Node*qtr = ptr->next;
    ptr->next = qtr->next;
    free(qtr);

    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

//indexing 0-->first node,1-->second node........................

    head->data = 7;
    head->next = second;

    second->data = 15;
    second->next = third;

    third->data = 37;
    third->next = fourth;

    fourth->data = 65;
    fourth->next = NULL;



    printf("linked list before deletion\n");
    LinkedListTraversal(head);
    head = delete_at_anyindex(head, 1);
    printf("linked list after deletion\n");
    LinkedListTraversal(head);
    return 0;
}