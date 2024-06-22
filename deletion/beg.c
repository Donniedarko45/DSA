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

struct Node*delete_at_beg(struct Node*head){
    struct Node*ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
int main(){

    struct Node*head=(struct Node*)malloc(sizeof(struct Node));
    struct Node*second=(struct Node*)malloc(sizeof(struct Node));
    struct Node*third=(struct Node*)malloc(sizeof(struct Node));
    struct Node*fourth=(struct Node*)malloc(sizeof(struct Node));


    head->data=7;
    head->next=second;

    second->data=15;
    second->next=third;

    third->data=37;
    third->next=fourth;

    fourth->data=65;
    fourth->next=NULL;
    printf("linked list before deletion\n");
    LinkedListTraversal(head);
    head=delete_at_beg(head);
    printf("linked list after deletion\n");
    LinkedListTraversal(head);
    return 0;
}