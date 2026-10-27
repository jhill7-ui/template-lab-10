/*
 * ICS 212 - Lab Week 10
 * Part I: Matrix Operations (includes Bonus: Matrix Transpose)
 *
 * Reads a matrix of integers (up to 5x5) from the user, then displays it,
 * its sum, its largest element, the average of each row, and its transpose.
 */

#include <stdio.h>

#define MAX 5   /* maximum number of rows and columns */

/* function prototypes */
void inputMatrix(int a[][MAX], int rows, int cols);
void displayMatrix(const int a[][MAX], int rows, int cols);
int sumMatrix(const int a[][MAX], int rows, int cols);
int findLargest(const int a[][MAX], int rows, int cols);
void rowAverages(const int a[][MAX], int rows, int cols);
void transposeMatrix(const int a[][MAX], int rows, int cols);

int main(void)
{
    int matrix[MAX][MAX];   /* local storage, no globals */
    int rows;
    int cols;

    /* read dimensions, repeating until both are in the range 1-5 */
    printf("Enter rows and columns (max 5x5): ");
    while (scanf("%d %d", &rows, &cols) != 2 ||
           rows < 1 || rows > MAX || cols < 1 || cols > MAX)
    {
        /* discard the rest of the line in case of bad input */
        while (getchar() != '\n')
        {
        }
        printf("Error: rows and columns must be between 1 and 5.\n");
        printf("Enter rows and columns (max 5x5): ");
    }

    inputMatrix(matrix, rows, cols);

    printf("\nMatrix:\n");
    displayMatrix(matrix, rows, cols);

    printf("\nSum: %d\n", sumMatrix(matrix, rows, cols));
    printf("Largest element: %d\n", findLargest(matrix, rows, cols));

    printf("\nRow averages:\n");
    rowAverages(matrix, rows, cols);

    printf("\nTranspose:\n");
    transposeMatrix(matrix, rows, cols);

    return 0;
}

/* reads rows * cols integers into the matrix, row by row */
void inputMatrix(int a[][MAX], int rows, int cols)
{
    int i;
    int j;

    printf("\nEnter %d elements:\n", rows * cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

/* prints the matrix, one row per line */
void displayMatrix(const int a[][MAX], int rows, int cols)
{
    int i;
    int j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/* returns the sum of all elements */
int sumMatrix(const int a[][MAX], int rows, int cols)
{
    int total = 0;
    int i;
    int j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            total += a[i][j];
        }
    }

    return total;
}

/* returns the largest element */
int findLargest(const int a[][MAX], int rows, int cols)
{
    int largest = a[0][0];   /* start with the first element */
    int i;
    int j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (a[i][j] > largest)
            {
                largest = a[i][j];
            }
        }
    }

    return largest;
}

/* prints the average of each row to two decimal places */
void rowAverages(const int a[][MAX], int rows, int cols)
{
    int i;
    int j;
    int rowSum;

    for (i = 0; i < rows; i++)
    {
        rowSum = 0;
        for (j = 0; j < cols; j++)
        {
            rowSum += a[i][j];
        }
        /* cast to double so the division is not integer division */
        printf("Row %d: %.2f\n", i + 1, (double) rowSum / cols);
    }
}

/*
 * Bonus: prints the transpose of the matrix.
 * Row i of the transpose is column i of the original, so the outer loop
 * goes over the original columns and the inner loop over the original rows.
 * The original matrix is not modified (it is const).
 */
void transposeMatrix(const int a[][MAX], int rows, int cols)
{
    int i;
    int j;

    for (j = 0; j < cols; j++)
    {
        for (i = 0; i < rows; i++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}