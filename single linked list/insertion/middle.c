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

// insertion at middle algorithm

void insertionAtMiddle(struct Node**head){
    struct Node*temp=*head;
    int data;
    printf("enter the data part of a Middle node which you want to insert: ");
    scanf("%d",&data);
    struct Node*new=(struct Node*)malloc(sizeof(struct Node));
    new->data=data;
    new->next=NULL;
    // now we have to do traversing and count how many nodes are there in our node then we have to do traversing if there is 7 nodes then we have to insert at 4 th posistion means prev 4 node now becomes at 5 th node => (n/2+1)..  suppose if we have 8 node then the insertion will be after 4 th node => (n/2 +1)

    // first we have to do traversing
    int count=0;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    } 
    
    temp=*head;
    int i=0;
    for(i=0;i<(count/2);i++){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;

}
int main()
{
    struct Node *head = NULL;
    node_creation(&head);
    linked_list_printing(&head);
    insertionAtMiddle(&head);
    linked_list_printing(&head);
}
