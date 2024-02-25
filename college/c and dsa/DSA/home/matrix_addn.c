/*write a program to add two matrices using array*/

#include <stdio.h>
int main()
{
    int i, j, p, q;
    // first matrix
    printf("enter no. of rows of matrix 1:");
    scanf("%d", &i);
    printf("enter no. of coloumns of matrix 1:");
    scanf("%d", &j);
    int arr[i][j];

    // second matrix..
    printf("enter no. of rows of matrix 2:");
    scanf("%d", &p);
    printf("enter no. of coloumns of matrix 2:");
    scanf("%d", &q);
    int brr[p][q];

    int res[i][j];
    if (i != p || j != q)
    {
        printf("matrix cant be added !");
    }
    else
    {
        // taking input of both matrix from user

        // matrix-1...
        printf("enter the number in matrix 1:\n");
        for (int a = 0; a < i; a++)
        {
            for (int b = 0; b < j; b++)
            {
                scanf("\n%d", &arr[a][b]);
            }
        }

        // taking input in matrix-2
        printf("enter the number in matrix 2:\n");
        for (int a = 0; a < i; a++)
        {
            for (int b = 0; b < j; b++)
            {
                scanf("\n %d", &brr[a][b]);
            }
        }

        // now adding...
        for (int a = 0; a < i; a++)
        {
            for (int b = 0; b < j; b++)
            {
                res[a][b] = arr[a][b] + brr[a][b];
            }
        }

        for (int a = 0; a < i; a++)
        {
            for (int b = 0; b < j; b++)
            {
                printf("%d ",res[a][b]);
            }
            printf("\n");
        }
    }
    return 0;
}

