#include <stdio.h> //for gets
#include <stdlib.h> //for atoi, itoa
#include <math.h>
#include <string.h> //for strlen
#include <ctype.h> //for isalpha


int main(int argc, char *argv[])
{
    if(argc == 1) //tutorial itself is an argument, hence we use argv[1] and argc must >=2
    {
        printf("Error: Invalid number of arguments.");
        return 1;
    }
    int key = atoi(argv[1]);
    char p[100];       //contains the plaintext

    printf("plaintext: ");
    gets(p);
    int length = strlen(p);

    for(int i = 0, n = length; i<n; i++)
    {
        if(key > 26)
        {
            key = key%26;
        }
        int ascnum = p[i] + key;
        // while key%26 != 0
        if(isalpha(p[i]))
        {
            if(isupper(p[i]))       //97 - 122 is a-z. 65-90 is A-Z
            {
                if(ascnum > 90)
                {
                    p[i] = ascnum - 90 + 64;
                }
                else
                {
                    p[i] = p[i] + key;
                }
            }
            else                    // lower case
            {
                if(ascnum > 122)
                {
                    p[i] = (ascnum - 122) + 96;
                }
                else
                {
                    p[i] = p[i] + key;
                }
            }
        }
    }
    printf("ciphertext: %s", p);
    return 0;

}
