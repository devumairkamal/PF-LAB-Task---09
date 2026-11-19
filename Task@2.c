#include <stdio.h>

/* Recursive function: prints the digits of num in reverse order */
void reverseDigits(long num)
{
    /* Base case: no digits left, so stop */
    if (num == 0)
    {
        return;
    }

    /* Print the last digit of the number */
    printf("%ld", num % 10);

    /* Call again with the number without its last digit */
    reverseDigits(num / 10);
}

int main(void)
{
    long num;

    printf("Enter number: ");
    scanf("%ld", &num);

    printf("Reversed: ");

    /* For a negative number, print the minus sign first and work with the positive value */
    if (num < 0)
    {
        printf("-");
        num = -num;
    }

    /* Zero has no digits to stop at, so print it directly */
    if (num == 0)
    {
        printf("0");
    }
    else
    {
        reverseDigits(num);
    }

    printf("\n");

    return 0;
}