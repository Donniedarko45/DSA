#include <stdio.h>
int main()
{
    int arr[] = {2, 8, 7, 4};
    int index, i, value;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("where you want to delete:  ");
    scanf("%d", &index);
    if(index<0||index>size-1){
        printf("index out of range !");
    }else{
    for(int i=index;i<size-1;i++)
    {
        arr[i]=arr[i+1];
    }
    size--;
    printf("new array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");}
    return 0;
}


