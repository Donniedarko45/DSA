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

struct Node*insert_at_end(struct Node*head,int data){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node*p=head;
    while(p->next!=NULL){
        p=p->next; //p ko aage badhate raho jabtak p ka next NULL na ho jaye
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

int main()
{
    // allocating memory for nodes in the linked list in heap..

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    // link first and second nodes..
    head->data = 4;
    head->next = second;

    // link second,third and fourth nodes
    second->data = 9;
    second->next = third;

    third->data = 17;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = NULL;
    printf("\nlinked list before insertion at end: \n");
    LinkedListTraversal(head);
    head = insert_at_end(head, 56);
    printf("\nlinked list after insertion at end: \n");
    LinkedListTraversal(head);
    return 0;
}