/**
  * Implement a program that prints out a half-pyramid of a specified height.
  */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n, height;
    
    // get height of pyramid from user
    do
    {
        printf("height: ");
        n = GetInt();
        height = n;
    } while ((n > 23) || (n < 0));

    int k = 0; 
    while (k < height) 
    {
        for (int i = n-1; i >= 0; i--)
        {  
            if (i != 0) 
            {
                printf(" ");
            } else 
            { 
                for (int j = 0; j <= k; j++) 
                { 
                    printf("#"); 
                }
                printf("#\n");
            }
        }
        k++;
        n--;
    }
    
    return 0;
}
