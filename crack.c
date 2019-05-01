#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <unistd.h>

int main(int argc, char *argv[]) //alphabetic password only, max 5 characters, salt == 50
{
    if(argc != 2)
    {
        printf("Error! Invalid number of commands (%i).", argc);
        return 1;
    }
    else
    {
        const char salt = "50";
        char *hashpw = argv[1];

        int lengthpw = strlen(argv[1]);

        for(int i=0; i<lengthpw; i++)
        {
            printf("%i: %c\n", i, hashpw[i]);
        }
        return 0;
    }
    //ga eerst na hoe de crack functie normaal werkt, reverse engineer het daarna
}
