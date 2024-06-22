#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* node_creation(struct Node **head)
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
    return *head;
}

//we have created linked list...++==>now lets delele first node of linked list..

struct Node* delete_at_beg(struct Node**head){
    // in delete at beg first we have to make a pointer which points to first node then head ko second note pe point krke first node ko free kr do
    struct Node*ptr=*head;
    *head=(*head)->next;
    free(ptr);
    return *head;
}

struct Node* linked_list_printing(struct Node**head){
    // taking a pointer and initialising it with ptr..for transversal..
    struct Node*ptr=(*head);
    while(ptr!=NULL){
        int i=0;
        printf("data part of %d node is: %d\n",i+1,ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct Node *head = NULL;
    node_creation(&head);
    head=delete_at_beg(&head);
    linked_list_printing(&head);
}