#include <stdio.h>

#define NUM_EMPLOYEES 3

/* Structure to store one employee's details */
struct Employee
{
    int id;
    char name[30];
    float salary;
};

int main(void)
{
    struct Employee emp[NUM_EMPLOYEES];
    int i;

    /* Input for all employees */
    for (i = 0; i < NUM_EMPLOYEES; i++)
    {
        printf("Enter ID, Name, Salary: ");
        scanf("%d %29s %f", &emp[i].id, emp[i].name, &emp[i].salary);

        /* Give a 10% raise only if salary is less than 50000 */
        if (emp[i].salary < 50000)
        {
            emp[i].salary = emp[i].salary + emp[i].salary * 0.10;
        }
    }

    /* Print updated records with 2 decimal places */
    printf("\n--- Updated Salaries ---\n");
    for (i = 0; i < NUM_EMPLOYEES; i++)
    {
        printf("%d %s %.2f\n", emp[i].id, emp[i].name, emp[i].salary);
    }

    return 0;
}