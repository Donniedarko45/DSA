// all posistion included start,end,in between start and end..

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

// now making fxn to make a linked list...

struct Node *linked_list_creation(struct Node**head){
    int no_of_nodes;
    printf("enter how many nodes do you want to enter in your linked list: ");
    scanf("%d",&no_of_nodes);
    struct Node*current=NULL; //iss pointer ka kam hai current node ko point krna mtlb ye ki jaise jaise temp me value aati rhegi waise waise ye latest node ko point krega...
    for(int i=0;i<no_of_nodes;i++){
        struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data part of node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;
        if(*head==NULL){
           *head=temp;
           //then abb current pointer latest temp wle ko point krega yai deal hua tha ....
           current=temp;
        }
        else{
            //agr pehle se hi value hai toh current pointer already point kr rha hai toh humme uske address part ko temp se update krna padega
            current->next=temp;
            // aur current pointer ko update kr doo..
            current=temp;
        }
    }
    return *head;
}

// now printing of node part comes...

void printing_of_linked_list(struct Node**head){
    //making a pointer for traversing which points to head..
    struct Node*ptr=(*head);
    int i=1;
    while(ptr!=NULL){
        printf("%d node is: %d \n",i,ptr->data);
        ptr=ptr->next;
        i++;
    }
}

//now lets make deleting algo's....++=>for deleting at any pos we want index also..

// some cases agr 1.{index<=0}=>invalid index   2. out of range ka and 3rd if head==NULL ho then...

struct Node* deleting_node_at_any_pos(struct Node **head) {
    int index;
    printf("Enter the index from where do you want to delete the node: ");
    scanf("%d", &index);

    // Validation: Check if index is valid
    if(index <= 0) {
        printf("Invalid index entered.\n");
        return *head;
    }

    // Traverse the linked list to find the node at the given index
    struct Node *prev = NULL;
    struct Node *curr = *head;
    int count = 1;

    while(curr != NULL && count < index) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    // agr index out of range ho toh..
    if(curr == NULL) {
        printf("Index out of range.\n");
        return *head;
    }

    // Delete the node at the given index
    if(prev == NULL) {  // Deleting the first node
        *head = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    printf("Node at index %d deleted successfully.\n", index);
    return *head;
}

int main(){
    struct Node*head=NULL;
    linked_list_creation(&head);
    head=deleting_node_at_any_pos(&head);
    printing_of_linked_list(&head);
}