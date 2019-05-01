#include <stdio.h>
#include <ctype.h>
#include <string.h>



int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("Error: Invalid number of arguments!");
        return 1;
    }
    if(isalpha(*argv[1])) //checks if the given key is alphabetic
    {
        char *keyletter = argv[1];
        int lengthkey = strlen(argv[1]);
        int keynumber[lengthkey];
        for(int i = 0; i < lengthkey; i++) //gives the alphabetic letters an actual value a, A = 0. z, Z = 25
            {
                if(isupper(keyletter[i]))
                {
                    keynumber[i] = keyletter[i] - 65;
                }
                else
                {
                    keynumber[i] = keyletter[i] - 97;
                }
             //printf("keynumber: %i\n", keynumber[i]);
            }

        char p[100];
        printf("plaintext: ");
        gets(p);
        int lengthtext = strlen(p);
        for(int i = 0, n = 0; n < lengthtext; i++, n++)
        {
            if(i == lengthkey)
            {
                i = 0;
            }
            int ascnum = p[n] + keynumber[i];
            if(isalpha(p[n]))
                {
                    if(isupper(p[n]))       //97 - 122 is a-z. 65-90 is A-Z
                    {
                        if(ascnum > 90)
                        {
                            p[n] = ascnum - 90 + 64;
                        }
                        else
                        {
                            p[n] = p[n] + keynumber[i];
                        }
                    }
                    else                    // lower case
                    {
                        if(ascnum > 122)
                        {
                            p[n] = (ascnum - 122) + 96;
                        }
                        else
                        {
                            p[n] = p[n] + keynumber[i];
                        }
                    }
                }
            else //this will make sure the key doesn't get used for a symbol or space.
            {
                i -= 1;
            }

        }
        printf("ciphertext: %s\n", p);
        return 0;
    }
    else
    {
        printf("Error: The given argument is not alphabetic.");
    }

}


