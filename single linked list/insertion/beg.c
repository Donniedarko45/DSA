#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void node_creation(struct Node **head)
{
    int no_of_nodes;
    printf("enter how many nodes do you want to insert in a linked list: ");
    scanf("%d", &no_of_nodes);
    int data;
    struct Node *current = NULL;
    for (int i = 0; i < no_of_nodes; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        printf("enter the data part of a %d node: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (*head == NULL)
        {
            *head = temp;
            current = temp;
        }
        else
        {
            current->next = temp;
            current = temp;
        }
    }
}
struct Node *linked_list_printing(struct Node **head)
{
    struct Node *ptr = (*head);
    int i = 0;
    while (ptr != NULL)
    {
        printf("data part of %d node is: %d\n", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

// insertion at begining algorithm

void insertionAtBeg(struct Node **head)
{
    // we have to insert a node at beg so what we have to do is to make a pointer which contains the address of a first node and then we have to link a newely created node to a head and then the pointer which stores the previously first node link it with newely added node

    struct Node *temp = *head;
    int data;
    printf("enter the data part of a node which you want to insert at begining posistion of linked list: ");
    scanf("%d", &data);
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    new->next=temp;
    *head=new;
}
int main()
{
    struct Node *head = NULL;
    node_creation(&head);
    linked_list_printing(&head);
    insertionAtBeg(&head);
    linked_list_printing(&head);
}
