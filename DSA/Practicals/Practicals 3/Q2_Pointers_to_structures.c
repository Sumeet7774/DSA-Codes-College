#include <stdio.h>
#include <conio.h>

struct mystruct
{
    int a,b;
};

int main()
{   
    struct mystruct *ptr = (struct mystruct *) malloc(sizeof(struct mystruct));

    printf("Enter the value of a: ");
    scanf("%d", &(ptr->a));

    printf("Enter the value of b: ");
    scanf("%d", &(ptr->b));

    printf("The sum is: %d ", ptr->a + ptr->b);

   return 0;
}