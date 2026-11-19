#include <stdio.h>

/*
 * Recursive function that processes one vehicle exit at a time.
 *   parked    : vehicles currently in the parking area
 *   exitsLeft : number of vehicles that still have to exit
 *   exitNo    : number of this exit (1st, 2nd, 3rd, ...)
 * Returns the number of vehicles remaining after all exits.
 */
int processExit(int parked, int exitsLeft, int exitNo)
{
    /* Base case: no more vehicles need to exit */
    if (exitsLeft == 0)
    {
        return parked;
    }

    /* One vehicle leaves the parking area */
    parked = parked - 1;
    printf("Exit %d: one vehicle left. Vehicles remaining: %d\n", exitNo, parked);

    /* Process the next exit */
    return processExit(parked, exitsLeft - 1, exitNo + 1);
}

int main(void)
{
    int totalParked;
    int exitCount;
    int remaining;
    int exited;

    printf("Enter total number of vehicles currently parked: ");
    scanf("%d", &totalParked);

    printf("Enter number of vehicles that will exit: ");
    scanf("%d", &exitCount);

    /* Vehicles cannot exit if there are not enough parked */
    if (totalParked < 0 || exitCount < 0 || exitCount > totalParked)
    {
        printf("Invalid input. Vehicles exiting cannot be more than vehicles parked.\n");
        return 1;
    }

    printf("\n--- Exit Process ---\n");
    remaining = processExit(totalParked, exitCount, 1);

    /* Total vehicles that exited */
    exited = totalParked - remaining;

    printf("\nTotal vehicles exited: %d\n", exited);
    printf("Vehicles remaining: %d\n", remaining);

    /* Check whether the parking area is empty at the end */
    if (remaining == 0)
    {
        printf("Parking area is now EMPTY.\n");
    }
    else
    {
        printf("Parking area is NOT empty.\n");
    }

    return 0;
}