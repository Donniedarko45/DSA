#include<stdio.h>
#include<stdlib.h>
//node is a self referential structure..
struct node{
    int data;
    struct node*link;   
}; 

//creating a node..
int main(){
  struct node*head=NULL;
  head=(struct node*)malloc(sizeof(struct node)); //now head contains address of first node
  head->data=45;
  head->link=NULL;
  printf("data part of first node is:%d",head->data);
  return 0;
}