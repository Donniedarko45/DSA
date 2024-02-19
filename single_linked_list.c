#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
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

    // printing data part of a node.

    current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->link;
    }
    return 0;
}