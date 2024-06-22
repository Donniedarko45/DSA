#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// there is three part in each node in double linked list prev node,next node ko link krne  ke liye pointer and a data part...

void linked_list_creation(struct Node **head)
{
    int no_of_nodes;
    printf("how many nodes do you want in your double linked list: ");
    scanf("%d", &no_of_nodes);
    struct Node *current = *head; // current pointer for traversal if linked list is empty it points to head..

    int data;
    for (int i = 0; i < no_of_nodes; i++)
    {
        // temp node bnaya jo temporarily store krega input value by user and is stored in the data part of the node..
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        printf("enter the data part of a %d node: ", i + 1, temp->data);
        scanf("%d", &temp->data);
        temp->prev = NULL; // temp-->is newely created node.. so this part do or sets temp ke prev part me NULL set kr dega..
        temp->next = NULL; // aur ye temp ke next me bhi NULL {ye sab naya node jaise bn rha tab ho raha soo hmare pass ekk current node {jo ki naya node hai usme abb hai prev me NULL next part me NULL aur data part which is entered by user}}

        if (*head == NULL) // checks whether linked list is empty or not....{=> if yes then it means there is no nodes in the list yet...}
        {
            // now abb iske andar aa gye it means linked list empty then kya kro head pointer ko point kra do temp pe jisse wo pehle link create ho jaye head ko temp.....=>{then abb ekk naya node hoga toh ye if statement wrong prove ho jayega aur sare conditions else mai chla jayega...} as iska kaam ye hai ki link krna first node ko apne linked list me...
            *head = temp;
            current = temp; // {it is a pointer which sets current pointer to newly created node...}
        }
        else
        {
            // till there if linked list is empty what we have done is to link the node to the head...then in the next iteration if=>condition becomes false as head do not now pointing to NULL {it is pointing to first node then it will move to the else part onward...}

            current->next = temp; 
            temp->prev = current;
            current = temp;
        }
    }
}
int main()
{
    struct Node *head = NULL;
    linked_list_creation(&head);
    return 0;
}