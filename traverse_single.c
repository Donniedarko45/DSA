// traversing a single linked list means visiting each node of a single linked list until the end node is reached..

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// Function to count the number of nodes in the linked list
void count_of_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    struct node *ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("Number of nodes in the linked list: %d\n", count);
    ptr=head; // doing this as we are traversing the linked list so ptr  is containg the address of last node and in its link part it is null so thats why we are again pointing ptr to its head part


    // printing data of each node:
        while (ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    
}
//  node creation..
int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 50;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 55;
    current->link = NULL;

    // now we have to update the 2nd node link part as it contain null and not pointing to a 3rd node so we have to update it how let's see:

    head->link->link = current;
    count_of_nodes(head);
    return 0;
}

//time complexity O(n)