#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;


void LinkedListTraversal(struct Node* ptr) {
    while(ptr != NULL) {
        printf("element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void Delete_last_Node(struct Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }

    struct Node* ptr = *head_ref;
    struct Node* qtr = NULL;

    while (ptr->next != NULL) {
        qtr = ptr;
        ptr = ptr->next;
    }

    qtr->next = NULL;
    free(ptr);
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 17;
    third->next = fourth;

    fourth->data = 15;
    fourth->next = NULL;

    printf("linked before deletion: \n");
    LinkedListTraversal(head);

    printf("\nlinked list after deletion: \n");
    Delete_last_Node(&head);
    LinkedListTraversal(head);

    return 0;
}
