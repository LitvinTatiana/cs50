#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void Vigebere(string key, string p);

int n, m;
int main (int argc, string argv[])
{
    //must be 2 command line argument
    if (argc!=2 )
    {
        printf("usage : ./vigenere + key \n");
        return 1;
    } else 
    {  
        //key is the second command line argument    
        string k = argv[1]; // Key
        m = strlen(k); 
        
        for (int i = 0; i < m; i++)
        { 
        	if (! isalpha(k[i]))
        	{
        	    printf("usage : ./vigenere + key \n");
        	    return 1;
        	}
        }
        
        string plaintext = GetString();
        n = strlen(plaintext);
        Vigebere(k, plaintext);
        return 0; 
    } 
}

void Vigebere(string key, string p)
{   
    char c [n]; 
    int j=0;
    
    // Loop through text
    for (int i = 0; i < n; i++)
    {
            // Keep case of letter
            if (isalpha(p[i]))
            { 
                j = j % m;                                  
                if (isupper(p[i]) && isupper(key[j])) 
                { 
                	c[i] =  ((p[i] + key[j] - 2*'A')) % 26 + 'A'; 
                } else 
                {
                	if (isupper(p[i]) && islower(key[j])) 
                	{ 
                		c[i] =  ((p[i]  + key[j] - 'A' - 'a')) % 26 + 'A'; 
                	} else
                	{
                			if (islower(p[i]) && isupper(key[j])) 
                			{ 
                				c[i] =  ((p[i]  + key[j] - 'a' - 'A')) % 26 + 'a'; 
                			} else
                			{
                				c[i] =  ((p[i]  + key[j] - 2*'a')) % 26 + 'a'; 
                				
                			}
                	}
                }
                j++;   
                
                            
            } else  c[i] = (char) p[i];
            
            printf("%c", (char) c[i]);
         }printf("\n");       
}
