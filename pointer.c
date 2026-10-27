/*
 * ICS 212 - Lab Week 10
 * Part II: Pointer Operations
 *
 * Exercise 1: update() modifies two variables through pointers.
 * Exercise 2: divideWithRemainder() returns two results through pointers.
 */

#include <stdio.h>

/* function prototypes */
void update(int *x, int *y);
void divideWithRemainder(int a, int b, int *quotient, int *remainder);

int main(void)
{
    int x;
    int y;
    int dividend;
    int divisor;
    int quotient;
    int remainder;

    /* ----- Exercise 1 ----- */
    printf("Exercise 1: Modify Two Variables\n");
    printf("Enter two integers (x y): ");
    scanf("%d %d", &x, &y);

    printf("Before: x = %d, y = %d\n", x, y);
    update(&x, &y);   /* pass the addresses so the function can change them */
    printf("After: x = %d, y = %d\n", x, y);

    /* ----- Exercise 2 ----- */
    printf("\nExercise 2: Quotient and Remainder\n");
    printf("Enter two integers: ");
    scanf("%d %d", &dividend, &divisor);

    /* the divisor must be nonzero before calling the function */
    while (divisor == 0)
    {
        printf("Error: divisor cannot be zero.\n");
        printf("Enter a new divisor: ");
        scanf("%d", &divisor);
    }

    divideWithRemainder(dividend, divisor, &quotient, &remainder);
    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);

    return 0;
}

/*
 * Doubles *x and adds the ORIGINAL value of *x to *y.
 * The original value is saved first, because *x is changed before
 * it would otherwise be used for *y.
 */
void update(int *x, int *y)
{
    int original = *x;

    *x = original * 2;
    *y = *y + original;
}

/* stores a / b in *quotient and a % b in *remainder (b must be nonzero) */
void divideWithRemainder(int a, int b, int *quotient, int *remainder)
{
    *quotient = a / b;
    *remainder = a % b;
}