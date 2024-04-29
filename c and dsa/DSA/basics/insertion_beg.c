#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void adding_elements(struct node *head)
{
    int nodes;
    printf("Enter how many nodes do you want: ");
    scanf("%d",&nodes);

    struct node *current =(struct node*)malloc(sizeof(struct node));
    current=head;

    for (int i = 0; i < nodes; i++)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        if (temp == NULL)
        {
            printf("Memory allocation failed!");
            exit(1);
        }

        printf("Enter data part of node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->link = NULL;

        current->link = temp;
        current = temp;
    }
}
void insertion_beg(struct node *head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }
    printf("Enter the data part of temp: ");
    scanf("%d",&temp->data);
    temp->link = head->link;
    head->link = temp; 
    head=temp; 
}
int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->link = NULL;

    // adding node at beg..
    insertion_beg(head);
    adding_elements(head);
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->link;
    }
    return 0;
}