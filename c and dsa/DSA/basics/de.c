#include <stdio.h>
#include <stdlib.h>
// Define a node structure for the linked list
struct Node
{
    int data;
    struct Node *next;
};
// Function to create a new node with the given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to insert a node at the beginning of the linked list
void insertAtBegin(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted at the beginning\n");
}
// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at the end");
}
// Function to insert a node at any specified position in the linked list
void insertAtPos(struct Node **head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid Position");
        return;
    }
    if (position == 1)
    {
        insertAtBegin(head, data);
    }
    else
    {
        struct Node *newNode = createNode(data);
        struct Node *temp = *head;
        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("Invalid Position\n");
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node inserted at the position %d", position);
        }
    }
}
// Function to display the linked list
void displayList(struct Node *head)
{
    printf("Linked list:");
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
// Function to delete a node at the beginning
struct Node *deleteAtBegin(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.Cannot delete from the beginning.\n");
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Deleted at the beginning.\n");
    return head;
}
// Function to delete a node at the end
struct Node *deleteAtEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.Cannot delete from the end.\n");
        return head;
    }
    if (head->next == NULL)
    {
        free(head);
        printf("Deleted at the end.\n");
        return NULL;
    }
    struct Node *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;

    printf("Delete at the end.\n");
    return head;
}
// Function to delete a node at any position
struct Node *deleteAtPos(struct Node *head, int position)
{
    if (head == NULL)
    {
        printf("List is empty.Cannot delete from the specified position.\n");
        return head;
    }
    if (position == 1)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        printf("Deleted at position %d.\n", position);
        return head;
    }
    struct Node *current = head;
    int i;
    for (i = 1; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }
    if (current == NULL || current->next == NULL)
    {
        printf("Invalid position.Cannot delete from position %d.\n", position);
        return head;
    }
    struct Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    printf("Deleted at position %d.\n", position);
    return head;
}
// Function to free the memory allocated for the linked list
void freeList(struct Node **head)
{
    struct Node *current = *head;
    struct Node *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert at the Beginning\n");
        printf("2. Insert at the End\n");
        printf("3. Insert at any Position\n");
        printf("4. Delete at the Beginning\n");
        printf("5. Delete at the End\n");
        printf("6. Delete at any Position\n");
        printf("7. Display the Linked List\n");
        printf("8. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert:");
            scanf("%d", &data);
            insertAtBegin(&head, data);
            break;
        case 2:
            printf("Enter data to insert:");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter data to insert:");
            scanf("%d", &data);
            printf("Enter position:");
            scanf("%d", &position);
            insertAtPos(&head, data, position);
            break;
        case 4:
            head = deleteAtBegin(head);
            break;
        case 5:
            head = deleteAtEnd(head);
            break;
        case 6:
            printf("Enter the position to delete:");
            scanf("%d", &position);
            head = deleteAtPos(head, position);
            break;
        case 7:
            displayList(head);
            break;
        case 8:
            // Free the memory before exiting
            freeList(&head);
            printf("Program terminated\n");
            break;
        default:
            printf("Invalid choice.Please enter a valid option");
        }
    } while (choice != 8);
    return 0;
}