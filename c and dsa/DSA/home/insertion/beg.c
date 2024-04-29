#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};

void LinkedListTraversal(struct Node*ptr){
    while(ptr!=NULL){
    printf("element: %d\n",ptr->data);
    ptr=ptr->next;
    }
}

struct Node*insertAtBeg(struct Node *head,int data)//humko data aur head cahiye
{
   struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
   ptr->next=head;
   ptr->data=data;
   return ptr;

}


int main(){
    // allocating memory for nodes in the linked list in heap..

    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth=(struct Node*)malloc(sizeof(struct Node));

    //link first and second nodes..
    head->data=4;
    head->next=second;

    // link second,third and fourth nodes
    second->data=9;
    second->next=third;

    
    third->data=17;
    third->next=fourth;
    
    fourth->data=15;
    fourth->next=NULL;

    LinkedListTraversal(head);
    head=insertAtBeg(head,56);
    LinkedListTraversal(head);
    return 0;
}