#include <stdio.h>

int main() {
    int arr[] = {2, 8, 7, 4};
    int index, value;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Where you want to add: ");
    scanf("%d", &index);

    // Ensure the index is valid
    if (index < 0 || index > size) {
        printf("Invalid index\n");
        return 1; // Return non-zero to indicate an error
    }

    printf("Value to insert: ");
    scanf("%d", &value);

    // Shift elements to make space for the new element
    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert the new element
    arr[index] = value;
    size++;

    // Print the modified array
    printf("Modified array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
