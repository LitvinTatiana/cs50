/**
* Implement a program that calculates the minimum number of coins required to give a user change.
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(int arge, string argv[])
{   
    float n;
    int f, count;
    count = 0;
    
    // get change owed, it is non-negative
    do
    {
        printf("O hai! How much change is owned? ");
        n = GetFloat();
        f = round(n*100); // avoid imprecision by converting to cents
    } while (n <= 0);
    
    // quarters
    while (25 <= f)
    {
        count++;
        f = f - 25;
    }
    
    // dimes
    while (10 <= f)
    {
        count++;
        f = f - 10;
    }
    
    // nickels
    while (5 <= f)
    {
        count++;
        f = f - 5;
    }
    
    // pennies
    while (1 <= f)
    {
        count++;
        f = f - 1;
    }
    
    // result   
    printf("%d\n", count);
}
