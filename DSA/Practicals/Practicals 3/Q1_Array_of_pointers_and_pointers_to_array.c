// 1. Write a program in C to implement arrays of pointers and pointers to arrays.

#include <stdio.h>
#include <conio.h>

void pointers_to_array(int arr[], int n, int *ptr[])            // implementing the concept of pointers to arrays
{
    for (int i = 0; i < n; i++)
    {
        ptr[i] = &arr[i];                           // assigning the address of each element to the pointer array which is ptr
    }

    printf("Printing the addresses of array elements using pointer: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%p ", ptr[i]);                      // printing the addresses of the values  // in c to print memory addresses we have to use %p
    }
    printf("\n\n");

    printf("Printing the values using array of pointers: \n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ",*ptr[i])                         ; // deferencing the pointer and printing the values of the array
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    int *ptr[n];

    printf("\n\n");

    printf("Enter the elements inside array: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n\n");

    pointers_to_array(arr,n,ptr);

    return 0;
}