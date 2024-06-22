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

// for printing..

struct Node* linked_list_printing(struct Node**head){
    // taking a pointer and initialising it with ptr..for transversal..
    struct Node*ptr=(*head);
    while(ptr!=NULL){
        int i=0;
        printf("data part of %d node is: %d\n",i+1,ptr->data);
        ptr=ptr->next;
    }
}

// making fxn to delete node at end..

struct Node* deleting_node_end(struct Node**head){
    // isme 2 pointer maintain kro ekk ko last pe le jao aur ekk ko (last-1) index pe...
    struct Node*ptr=(*head);
    struct Node*qtr=ptr->next; // ye last index pe rhega pointer
    while(qtr->next!=NULL){  //jab tak qtr->next part NULL na ho jaye tabtak traverse kro
        ptr=ptr->next;
        qtr=qtr->next;
    }
    ptr->next=NULL;
    free(qtr);
    return *head;
}


int main(){
    struct Node*head=NULL;
    node_creation(&head);
    head=deleting_node_end(&head);
    printf("linked list after removing the end node: \n");
    linked_list_printing(&head);
}