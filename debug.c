/*
 * ICS 212 - Lab Week 10
 * Part III: Debugging
 */

#include <stdio.h>

/* stores 10 in the variable that p points to */
void setValue(int *p)
{
    *p = 10;
}

int main(void)
{
    int x = 0;

    /*
     * Original call: setValue(x);
     * This was incorrect because setValue() expects a POINTER to an int
     * (int *), but x is an int. Passing x sends the VALUE 0, which the
     * function would then treat as a memory address and try to write to,
     * causing a compiler error/warning and a crash at run time. Even if it
     * did not crash, x itself could never be changed, because only a copy
     * of its value is passed.
     *
     * Fix: pass the ADDRESS of x with the & operator, so p points to x
     * and *p = 10 changes x itself.
     */
    setValue(&x);

    printf("x = %d\n", x);   /* prints x = 10 */

    return 0;
}