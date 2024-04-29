#include<stdio.h>
int main(){
    int arr[]={1,5,8,74,54};
    int size=sizeof(arr)/sizeof(arr[0]);
    //now we have to delete at end
    printf("new array is: ");
    for(int i=0;i<size-1;i++){
       printf(" %d ",arr[i]);
    }
    return 0;
}
