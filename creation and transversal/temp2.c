#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

struct Node*create(struct Node**head){
    int no_of_nodes;
    printf("enter how many nodes do you want: ");
    scanf("%d",&no_of_nodes);
    struct Node*temp=*head;
    for(int i=0;i<no_of_nodes;i++){
        struct Node*current=(struct Node*)malloc(sizeof(struct Node));
        printf("enter the data part of a %d node: ",i+1);
        scanf("%d",&current->data);
        current->next=NULL;
        if(*head==NULL){
        *head=current;
        temp=current;
    }
    else{
        temp->next=current;
        temp=current;
    }
    }
    }
    
struct Node*linked_list_printing(struct Node**head){
    struct Node*current=*head;
    int i=0;
    while(current!=NULL){
        
        printf("data part of a %d node is: %d\n",i+1,current->data);
        current=current->next;
        i++;
    }
}


int main(){
    struct Node*head=NULL;
    create(&head);
    linked_list_printing(&head);
    return 0;
}