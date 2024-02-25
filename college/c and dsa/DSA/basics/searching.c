#include <stdio.h>
int main()
{
    int value;
    int arr[] = {4, 8, 26, 63, 54, 58, 69};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("enter the value to search from existing array: ");
    scanf("%d", &value);
    for (int i = 0; i <= size - 1; i++)
    {
        if (arr[i] == value)
        {
            printf("entered number exist in an array and its index is: %d", i);
        }
    }

}