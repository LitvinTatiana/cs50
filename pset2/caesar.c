#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void Caesar(int key, string p);
void makeabc(int a);

int n;
// plaintext
// ciphertext
int main (int argc, string argv[])
{
    //must be 2 command line arguments
    if (argc!=2)
    {
        printf("usage : ./caesar + key \n");
        return 1;
    }
    else {
        // key is the second command line argument 
        // convert input to int type   
        int k = atoi(argv[1]);
        // get text to encode
        string plaintext = GetString();
        n = strlen(plaintext);
        Caesar(k,plaintext);

        return 0; 
        } 
}

void Caesar(int key, string p)
{   
    char c [n], abc [n], ABC [n]; 
    
     // loop through text
    for (int i = 0; i < n; i++)
    {
        // keep case of letter
        if (isalpha(p[i]))
        {   
            if (isupper(p[i])) 
            {  
                for (int j = 0; j<26; j++)
                       { 
                            ABC[j]= 65 + j;
                       }
                       
                for (int j = 0; j<26; j++)       
                       {
                           if (ABC[j] == p[i])
                               c[i] = ABC[(j + key) % 26];
                       }

            } else // islower
            {
                //
                for (int j = 0; j<26; j++)
                       { 
                            abc[j]= 'a' + j;
                       }
                       
                for (int j = 0; j<26; j++)
                       { 
                            if (abc[j] == p[i])
                                c[i] = abc[(j + key) % 26];
                       }
                //
            }
            
        } else  c[i] = (char) p[i];
        
        printf("%c", c[i]);
    }
    printf("\n");

}
