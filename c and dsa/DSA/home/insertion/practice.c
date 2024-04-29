// suppose we have given a q pointer which points at some index of linked list and we have to insert a node after that index...


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

struct Node*insertion_at_after_Node(struct Node*head,struct Node*prevNode,int data){
    // first we have to allocate a memory 
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=prevNode->next;  // ptr ke next me jo previous node uske next part ka address dal do.....

    prevNode->next=ptr;
    return head;
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
    printf("linked before insertion: \n");
    LinkedListTraversal(head);
    printf("\nlinked list after insertion: \n");
    head=insertion_at_after_Node(head,second,58);
    LinkedListTraversal(head);

}