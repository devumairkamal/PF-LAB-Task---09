#include <stdio.h>

/* Recursive function: returns the total calories burned after climbing n steps */
int totalCalories(int n)
{
    /* Base case: no steps climbed means no calories burned */
    if (n == 0)
    {
        return 0;
    }

    /* Calories of step n = n * 5, plus the calories of all earlier steps */
    return (n * 5) + totalCalories(n - 1);
}

int main(void)
{
    int steps;
    int total;

    printf("Enter number of steps: ");
    scanf("%d", &steps);

    if (steps < 0)
    {
        printf("Number of steps cannot be negative.\n");
        return 1;
    }

    total = totalCalories(steps);

    printf("Total calories burned: %d\n", total);

    return 0;
}