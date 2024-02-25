#include <stdio.h>
int main()
{
    int n;
    printf("enter the size of array : ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i <= n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }

    int index, value;
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("where you want to add:  "); // getting index of element where to add the element
    scanf("%d", &index);
    printf("value of index is: ");
    scanf("%d", &value);

    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[index] = value;
    printf("Modified array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}