#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

void adding_elements(struct node** head){
    struct node *current = NULL;
    int no_of_nodes;
    printf("Enter how many nodes do you want to add in a linked list: ");
    scanf("%d", &no_of_nodes);
    
    for(int i = 0; i < no_of_nodes; i++){
        struct node* temp = (struct node*)malloc(sizeof(struct node));

        printf("Enter data part of node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->link = NULL;

        if (*head == NULL) {
            *head = temp;   // Set head if it's NULL
            current = temp;
        } else {
            current->link = temp;
            current = temp;
        }
    }
}

void insert_any_pos(struct node** head, int data, int pos){
    if (*head == NULL && pos != 1) {
        printf("List is empty, can't insert at position %d\n", pos);
        return;
    }

    struct node* ptr = *head;
    struct node* ptr2 = (struct node*)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    if (pos == 1) {
        ptr2->link = *head;
        *head = ptr2;
        return;
    }

    pos--;
    while (pos != 1) {
        if (ptr == NULL) {
            printf("Invalid position\n");
            free(ptr2);
            return;
        }
        ptr = ptr->link;
        pos--;
    }

    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

int main(){
    struct node* head = NULL;
    int position, data;

    printf("Enter position where you want to insert: ");
    scanf("%d", &position);
    printf("Enter the data of a node: ");
    scanf("%d", &data);

    adding_elements(&head);
    insert_any_pos(&head, data, position);

    struct node* ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    return 0;
}
