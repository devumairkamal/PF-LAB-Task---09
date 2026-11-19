#include <stdio.h>

#define FILE_NAME "library.txt"

/* Adds new book records to the end of the file. Old records stay unchanged. */
void addBooks(void)
{
    FILE *fp;
    int id;
    char title[30];
    char author[30];
    char more = 'y';

    fp = fopen(FILE_NAME, "a");
    if (fp == NULL)
    {
        printf("Error: cannot open file.\n");
        return;
    }

    while (more == 'y' || more == 'Y')
    {
        printf("Enter Book ID: ");
        scanf("%d", &id);

        printf("Enter book title (use _ for spaces): ");
        scanf("%s", title);

        printf("Enter author name (use _ for spaces): ");
        scanf("%s", author);

        fprintf(fp, "%d %s %s\n", id, title, author);
        printf("Book record saved.\n");

        printf("Add another book? (y/n): ");
        scanf(" %c", &more);
    }

    fclose(fp);
}

/* Shows all book records in the file */
void showBooks(void)
{
    FILE *fp;
    int id;
    char title[30];
    char author[30];
    int count = 0;

    fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf("No records found. Add books first.\n");
        return;
    }

    printf("\n--- All Books ---\n");

    while (fscanf(fp, "%d %s %s", &id, title, author) == 3)
    {
        printf("ID: %-5d Title: %-20s Author: %s\n", id, title, author);
        count++;
    }

    if (count == 0)
    {
        printf("The library file is empty.\n");
    }

    fclose(fp);
}

/* Searches for a book by its ID and shows its full details */
void searchBook(void)
{
    FILE *fp;
    int searchId;
    int id;
    char title[30];
    char author[30];
    int found = 0;

    printf("Enter Book ID to search: ");
    scanf("%d", &searchId);

    fp = fopen(FILE_NAME, "r");
    if (fp == NULL)
    {
        printf("No records found. Add books first.\n");
        return;
    }

    while (fscanf(fp, "%d %s %s", &id, title, author) == 3)
    {
        if (id == searchId)
        {
            printf("\nBook found!\n");
            printf("Book ID : %d\n", id);
            printf("Title   : %s\n", title);
            printf("Author  : %s\n", author);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (found == 0)
    {
        printf("No book found with ID %d.\n", searchId);
    }
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

    /* Create library.txt if it does not exist yet */
    fp = fopen(FILE_NAME, "a");
    if (fp != NULL)
    {
        fclose(fp);
    }

    while (choice != 5)
    {
        printf("\n===== Library Menu =====\n");
        printf("1. Add book records\n");
        printf("2. Display all books\n");
        printf("3. Search book by ID\n");
        printf("4. Delete library file\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addBooks();
        }
        else if (choice == 2)
        {
            showBooks();
        }
        else if (choice == 3)
        {
            searchBook();
        }
        else if (choice == 4)
        {
            deleteFile();
        }
        else if (choice == 5)
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