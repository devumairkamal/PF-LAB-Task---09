#include <stdio.h>

#define NUM_BOOKS 3

/* Structure to store one book's details */
struct Book
{
    int id;
    char title[50];
    float price;
};

int main(void)
{
    struct Book books[NUM_BOOKS];
    int i;
    int maxIndex = 0;   /* index of the most expensive book so far */

    /* Read details of all books */
    for (i = 0; i < NUM_BOOKS; i++)
    {
        printf("Enter ID, Title, Price of book %d: ", i + 1);
        scanf("%d %49s %f", &books[i].id, books[i].title, &books[i].price);

        /* Track the index of the highest price while reading input */
        if (books[i].price > books[maxIndex].price)
        {
            maxIndex = i;
        }
    }

    /* Display all books */
    printf("\n--- Book List ---\n");
    for (i = 0; i < NUM_BOOKS; i++)
    {
        printf("%d %s Rs.%.2f\n", books[i].id, books[i].title, books[i].price);
    }

    /* Display the most expensive book */
    printf("Most expensive: %s (Rs.%.2f)\n", books[maxIndex].title, books[maxIndex].price);

    return 0;
}