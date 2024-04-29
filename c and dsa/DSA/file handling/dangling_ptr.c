#include<stdio.h>
int* fun(){
    int num=10;
    return &num;
}
int main(){
    int num=10;
    int* ptr=NULL;
    ptr=fun();
    printf("%d",*ptr);
    return 0;
}