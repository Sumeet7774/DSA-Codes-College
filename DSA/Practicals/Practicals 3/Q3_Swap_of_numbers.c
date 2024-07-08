#include <stdio.h>
#include <conio.h>

void swap(int *ptr1, int *ptr2)
{
    int temp;

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{
    int a,b;

    printf("Enter the value of a: ");
    scanf("%d",&a);

    printf("Enter the value of b: ");
    scanf("%d",&b);

    printf("\n\n");

    printf("Before swapping the values of a and b are: %d %d",a,b);
    printf("\n\n");

    swap(&a,&b);
    printf("After swapping the values of a and b are: %d %d", a,b);

   return 0;
}