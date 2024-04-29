#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,num;
    printf("enter the size of integers: ");
    scanf("%d",&n);
    int *ptr=(int*)malloc(n*sizeof(int)); //n-->total no of elements so total size= n*size of 1 integer 
    if(ptr==NULL){
        printf("memory not available");
        exit(1);
    }else{
        for(int i=0;i<n;i++){
            printf("enter an integer: ");
            scanf("%d",ptr+i); // ptr contains first element address so i=0,i=1,i=2,i=3,....lets say first ptr stores ptr=1000..(ptr+i)=(1000,1000+(1*4),1000+(2*4),1000+(3*4).......) 
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",*(ptr+i));
    }
     return 0;
}