#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// first create linked list-->that will do take input from users how many nodes do you want in your linked list taking input from users from terminal and ...............


// making fxn for taking data from user..

void node_creation(struct Node **head)
{
    int no_of_nodes;
    printf("enter how many nodes do you want to insert in a linked list: ");
    scanf("%d", &no_of_nodes);

    int data; // it will store data part  of a node..

    struct Node *current = NULL; // a pointer for traversal..

    // so for every nodes we are going to create we have to allocate memory for this...

    for (int i = 0; i < no_of_nodes; i++)
    {
        //allocating memory that is equal to size of struct nodes in bytes..

        struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); 

        printf("enter the data part of a %d node: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (*head == NULL) // if it is true it indicates that linked list is currently empty..
        {
            *head = temp; // if linked is empty then.. head pointer jo hai wo {newely created jo node bnaya h}usko point krega..

            current = temp; // current pointer ko update kr do newely created node {jo temp hai} usse..

            // {now both head and current pointer points to the same node temp}==>current keeps track of the last node of the linked list as of now if we are in first iteration of a loop there is only one node created and current pointer points to the first node if we are in second iteration when second node is created then current pointer now points to the second node...
        }
        else // matlab pehle se hi hai node toh dekhte hai aage kaise krna hai
        {
            current->next = temp; // now current pointer->{first node ko point kr rha hai} so it access the 'next' pointer of the current node {next pointer ka matlab ye nai hai ki next node ke pointer ko point kr rha} in a node of temp there is next part aur tabb iska mtlb ye hua ki ye temp jo ki current node hai usko represent kr rha hai current->next}

            current = temp; //updating the current pointer to point to the newly created node temp 
        }
    }
} // node is created onto next.....==>jst one more task create print fxn of the linked list..

struct Node* linked_list_printing(struct Node**head){
    // taking a pointer and initialising it with ptr..for transversal..
    struct Node*ptr=(*head);
    while(ptr!=NULL){
        int i=0;
        printf("data part of %d node is: %d\n",i+1,ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct Node *head = NULL;
    node_creation(&head);
    linked_list_printing(&head);
}