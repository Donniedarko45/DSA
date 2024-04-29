#include <stdio.h>
int main()
{
    int arr[] = {1, 8, -5, 9, 7, 4, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sub_array_size;
    int max_sum = arr[0];
    int max_index = 0;

    printf("Enter the size of the sub-array: ");
    scanf("%d", &sub_array_size);

    int sum = 0;
    for (int i = 0; i < sub_array_size; i++)
    {
        sum = 0;
        for (int j = i; j < i + sub_array_size; j++)
        {
            sum = sum + arr[j];
        }
        if (sum > max_sum)
        {
            max_sum = sum;
            max_index = i;
        }
    }

    printf("Max of sum of subarray is %d and it starts from index %d to %d.", max_sum, max_index,max_index+sub_array_size-1);

    return 0;
}