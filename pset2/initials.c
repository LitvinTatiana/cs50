#include <cs50.h>
#include <stdio.h>
#include <string.h>

void PrintName(string s);
int j; char res[10];
int main (void)
{   
    string name = GetString();
    PrintName(name);
    
}

void PrintName(string s)
{   
    //Is empty?
    if (s != NULL)
    {   int j = 0;
        if (!(s[0]==' ')) 
        {
            res[0] = s[0];
            j++;
        } 
       
        //Find words
         for (int i = 1, n = strlen(s); i < n; i++) 
          {              
                if (s[i]!=32 && s[i-1]==32)
                {
                    res[j] = s[i];
                    j++;
                }
          }
          //Make high register
          for (int k = 0; k < j; k++)
          {     
                if (res[k]>='a'&& res[k]<='z')
                {
                res[k] = res[k] - ('a'-'A');
                }
                printf("%c", res[k]);
                
          }
     }
     printf("\n");
     
}
