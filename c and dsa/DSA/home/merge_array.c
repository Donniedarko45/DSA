/* merge the two arrays in single array*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1, 3, 5, 7, 9};
    int brr[] = {2, 4, 6, 8, 10};

    int size1 = sizeof(arr) / sizeof(arr[0]);
    int size2 = sizeof(brr) / sizeof(brr[0]);

    // total size when new array will form is combination of both arrays

    int new_size = size1 + size2;

    int *new_arr = (int *)malloc(new_size * sizeof(int));
    if (new_arr == NULL)
    {
        printf("memory allocation failed \n");
        return 1;
    }

    // Merge the arrays
    int i, j, k;
    i = j = k = 0;

    for (i = 0, j = 0, k = 0; i < size1 && j < size2;)
    {
        if (arr[i] < brr[j])
        {
            new_arr[k++] = arr[i++];
        }
        else
        {
            new_arr[k++] = brr[j++];
        }
    }

    for (; i < size1;)
    {
        new_arr[k++] = arr[i++];
    }

    for (; j < size2;)
    {
        new_arr[k++] = brr[j++];
    }

    printf("after merging: ");
    for (int i = 0; i < new_size; i++)
    {
        printf("%d ", new_arr[i]);
    }
    printf("\n");
    return 0;
}
