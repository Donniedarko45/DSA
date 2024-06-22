#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void NodeCreation(struct Node **head)
{
    int noOfNodes;
    printf("enter how many nodes do you want in your linked list: ");
    scanf("%d", &noOfNodes);
    int data;

    struct Node *current = NULL;

    for (int i = 0; i < noOfNodes; i++)
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

// algorithm for insertion at end

void insertionAtEnd(struct Node **head)
{
    struct Node *ptr = (*head);

    // first we have to do traversing and have to add a node at node the steps involves is we have to update the the prev last node addresss part
    int count = 0;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        count++;
    }

    // lets make a node which we want to add:
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    int data;
    printf("enter a data part of a new Node: ");
    scanf("%d", &data);
    new->data = data;
    new->next = NULL;

    // traversing so that ptr pointer goes to last node..

    for (int i = 0; i < count; i++)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
}
struct Node *linkedListPrinting(struct Node **head)
{
    struct Node *ptr = (*head);
    int i = 0;
    while (ptr != NULL)
    {
        printf("data part of a %d node is %d: ", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

int main()
{
    struct Node *head = NULL;
    NodeCreation(&head);
    insertionAtEnd(&head);
    linkedListPrinting(&head);
}
