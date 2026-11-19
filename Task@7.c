#include <stdio.h>

#define FILE_NAME "attendance.txt"

/* Adds new student records to the end of the file. Old records are kept. */
void addRecords(void)
{
    FILE *fp;
    char name[30];
    int roll;
    char status;
    char more = 'y';

    /* "a" means append: new data goes at the end, old data stays */
    fp = fopen(FILE_NAME, "a");
    if (fp == NULL)
    {
        printf("Error: cannot open file.\n");
        return;
    }

    while (more == 'y' || more == 'Y')
    {
        printf("Enter student name (use _ for spaces): ");
        scanf("%s", name);

        printf("Enter roll number: ");
        scanf("%d", &roll);

        /* Ask again until the user types P or A */
        do
        {
            printf("Enter status (P = Present, A = Absent): ");
            scanf(" %c", &status);
        } while (status != 'P' && status != 'p' && status != 'A' && status != 'a');

        if (status == 'P' || status == 'p')
        {
            fprintf(fp, "%s %d Present\n", name, roll);
        }
        else
        {
            fprintf(fp, "%s %d Absent\n", name, roll);
        }

        printf("Record saved.\n");

        printf("Add another record? (y/n): ");
        scanf(" %c", &more);
    }

    fclose(fp);
}

/* Shows all records saved in the file */
void showRecords(void)
{
    FILE *fp;
    char name[30];
    int roll;
    char status[10];
    int count = 0;

    fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf("No records found. Add records first.\n");
        return;
    }

    printf("\n--- Attendance Records ---\n");

    /* Read one record (name, roll, status) at a time */
    while (fscanf(fp, "%s %d %s", name, &roll, status) == 3)
    {
        printf("Name: %-15s Roll No: %-5d Status: %s\n", name, roll, status);
        count++;
    }

    if (count == 0)
    {
        printf("The file is empty.\n");
    }

    fclose(fp);
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
    FILE *fp;
    int choice = 0;

    /* Create attendance.txt if it does not exist yet */
    fp = fopen(FILE_NAME, "a");
    if (fp != NULL)
    {
        fclose(fp);
    }

    while (choice != 4)
    {
        printf("\n===== Attendance Menu =====\n");
        printf("1. Add records\n");
        printf("2. Display all records\n");
        printf("3. Delete file\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addRecords();
        }
        else if (choice == 2)
        {
            showRecords();
        }
        else if (choice == 3)
        {
            deleteFile();
        }
        else if (choice == 4)
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