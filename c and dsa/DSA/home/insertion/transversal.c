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
int main(){
    // allocating memory for nodes in the linked list in heap..

    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third=(struct Node*)malloc(sizeof(struct Node));

    //link first and second nodes..
    head->data=7;
    head->next=second;

    // link second and third nodes
    second->data=15;
    second->next=third;

    //terminate the linked list at the third nodes
    third->data=37;
    third->next=NULL;

    LinkedListTraversal(head);
    return 0;
}