#include <stdio.h>

#define MAX_PRODUCTS 100

/*
 * Recursive function: adds the price of one product at a time.
 * It starts at 'index' and keeps going until all products (up to 'count') are included.
 */
float calculateTotal(float prices[], int count, int index)
{
    /* Base case: every product has been processed */
    if (index == count)
    {
        return 0.0;
    }

    /* Price of this product + total of the remaining products */
    return prices[index] + calculateTotal(prices, count, index + 1);
}

int main(void)
{
    float prices[MAX_PRODUCTS];
    int count;
    int i;
    float total;
    float average;

    printf("Enter number of products: ");
    scanf("%d", &count);

    if (count <= 0 || count > MAX_PRODUCTS)
    {
        printf("Invalid number of products. Enter a value between 1 and %d.\n", MAX_PRODUCTS);
        return 1;
    }

    /* Take the price of each product */
    for (i = 0; i < count; i++)
    {
        printf("Enter price of product %d: Rs. ", i + 1);
        scanf("%f", &prices[i]);
    }

    /* Calculate the total bill using recursion, starting from product 0 */
    total = calculateTotal(prices, count, 0);

    /* Average price of the products */
    average = total / count;

    printf("\nTotal bill: Rs. %.2f\n", total);
    printf("Average price of products: Rs. %.2f\n", average);

    return 0;
}