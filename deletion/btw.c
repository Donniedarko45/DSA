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

struct Node*delete_btw(struct Node*head,int index){
    struct Node*ptr=head; //abb ptr pointer ko (index-1) and qtr pointer ko index tak leke jana h..
    int i=1;
    while(i!=index-1){
        ptr=ptr->next;
        i++;
    }
    struct Node*qtr=ptr->next;
    // then what we have to do is that qtr is pointing at index that is we want to delete so first we have to link (index-1) ko (index+1) wale se ptr->next=qtr->next and then free the qtr....
    ptr->next=qtr->next;
    free(qtr);
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
    head=delete_btw(head,3);
    printf("linked list after deletion\n");
    LinkedListTraversal(head);
    return 0;
}