#include <stdio.h>

#define FILE_NAME "employees.dat"

/* Structure to store one employee */
struct Employee
{
    int id;
    char name[30];
    float salary;   /* monthly salary */
};

/* Returns 1 if the file exists, otherwise 0 */
int fileExists(void)
{
    FILE *fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        return 0;
    }

    fclose(fp);
    return 1;
}

/*
 * Adds employees to the binary file (old records are kept).
 * minimum = how many records must be entered before the user can stop.
 *           Use 5 when creating the file, and 0 when adding to an existing file.
 */
void addEmployees(int minimum)
{
    FILE *fp;
    struct Employee emp;
    int count = 0;
    char more = 'y';

    /* "ab" means append to a binary file */
    fp = fopen(FILE_NAME, "ab");
    if (fp == NULL)
    {
        printf("Error: cannot open file.\n");
        return;
    }

    while (count < minimum || more == 'y' || more == 'Y')
    {
        printf("Enter Employee ID: ");
        scanf("%d", &emp.id);

        printf("Enter Name (use _ for spaces): ");
        scanf("%s", emp.name);

        printf("Enter Monthly Salary: ");
        scanf("%f", &emp.salary);

        /* Write the whole record to the binary file */
        fwrite(&emp, sizeof(struct Employee), 1, fp);
        count++;
        printf("Employee saved.\n");

        if (count >= minimum)
        {
            printf("Add another employee? (y/n): ");
            scanf(" %c", &more);
        }
    }

    fclose(fp);
}

/* Reads and shows all employee records */
void showAll(void)
{
    FILE *fp;
    struct Employee emp;
    int count = 0;

    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("No employee file found.\n");
        return;
    }

    printf("\n--- All Employees ---\n");

    /* Read one record at a time */
    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1)
    {
        printf("ID: %-5d Name: %-15s Salary: Rs. %.2f\n", emp.id, emp.name, emp.salary);
        count++;
    }

    printf("Total records: %d\n", count);

    fclose(fp);
}

/* Searches for an employee by ID and shows full details */
void searchEmployee(void)
{
    FILE *fp;
    struct Employee emp;
    int searchId;
    int found = 0;

    printf("Enter Employee ID to search: ");
    scanf("%d", &searchId);

    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("No employee file found.\n");
        return;
    }

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1)
    {
        if (emp.id == searchId)
        {
            printf("\nEmployee found!\n");
            printf("ID     : %d\n", emp.id);
            printf("Name   : %s\n", emp.name);
            printf("Salary : Rs. %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found == 0)
    {
        printf("No employee found with ID %d.\n", searchId);
    }
}

/* Adds up the monthly salary of all employees */
void totalSalary(void)
{
    FILE *fp;
    struct Employee emp;
    float total = 0;
    int count = 0;

    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("No employee file found.\n");
        return;
    }

    while (fread(&emp, sizeof(struct Employee), 1, fp) == 1)
    {
        total = total + emp.salary;
        count++;
    }

    fclose(fp);

    printf("Total monthly salary of %d employees: Rs. %.2f\n", count, total);
}

/* Deletes the whole file */
void deleteFile(void)
{
    if (remove(FILE_NAME) == 0)
    {
        printf("File deleted.\n");
    }
    else
    {
        printf("File not found. Nothing to delete.\n");
    }
}

int main(void)
{
    int choice = 0;

    /* The file must have at least 5 employees when it is first created */
    if (fileExists() == 0)
    {
        printf("Please enter at least 5 employee records first.\n");
        addEmployees(5);
    }

    while (choice != 6)
    {
        printf("\n===== Employee Salary Menu =====\n");
        printf("1. Add employee records\n");
        printf("2. Display all employees\n");
        printf("3. Search employee by ID\n");
        printf("4. Show total monthly salary\n");
        printf("5. Delete employee file\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (fileExists() == 1)
            {
                addEmployees(0);
            }
            else
            {
                /* File was deleted, so it must be created again with at least 5 records */
                printf("Please enter at least 5 employee records first.\n");
                addEmployees(5);
            }
        }
        else if (choice == 2)
        {
            showAll();
        }
        else if (choice == 3)
        {
            searchEmployee();
        }
        else if (choice == 4)
        {
            totalSalary();
        }
        else if (choice == 5)
        {
            deleteFile();
        }
        else if (choice == 6)
        {
            printf("Goodbye!\n");
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}