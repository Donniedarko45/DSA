#include<stdio.h>
int main(){
    int n;
    printf("enter how many elements: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //now we have to find largest
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>arr[0]){
            largest=arr[i];
        }
    }
    printf("%d",largest);
}