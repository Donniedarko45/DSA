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
    head->data = 55;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 60;
    current->link = NULL;
    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 65;
    current->link = NULL;
    head->link->link = current;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    printf("enter the data part of temp: ");
    scanf("%d", &temp->data);
    // its obvious that temp->link=NULL as temp will be last node of a node.
    temp->link = NULL;
    // head->link->link->link=temp instead of doing this we can directly write as "current" pointer is in already previous last node so we can directly write..
    current->link = temp;

    current = head;
    while (head != NULL)
    {
        printf("%d ", current->data);
        current = current->link;
    }
}
// time complexity=O(1)