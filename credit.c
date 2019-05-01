#include <stdio.h>
#include <stdlib.h>

long long length(long long number);
void cc_check(long long number, long long length);
void is_visa(long long number, long length);

int main()
{
    long long cc_number;
    printf("Number: ");
    scanf("%lli", &cc_number);
    //long long cc_length = length(cc_number);
    //cc_check(cc_number, cc_length);
    return 0;
}
/*
//functions

long long length(long long number)
{
    long long counter;
    for(counter = 0; number > 0; counter++)
    {
        number = number/10;
    }
    return counter;
}
/*
VISA: 13 and 16 digits - start with 4
AMERICAN EXPRESS: 15 digits - starts with 34 or 37
MASTERCARD: 16 digits - starts with 51, 52, 53, 54, or 55
*/
/*
void cc_check(long long number, long long length)
{
     if(length < 13 || length > 16)
    {
        printf("INVALID");
    }
    else if(length == 13)
    {
        is_visa(number, length);
    }
}

// check visa
void is_visa(long long number, long length)
{
    long long digit[13];
    long long i = 1;
    // makes an array with the digits in correct order, digit[0] gives the first, digit[12] the last.
    for(long long counter = 12; counter>=0; counter--)
    {
        digit[counter] = (number/i)%10;
        i *=10;
    }

/*
    long result;

    for(long long x = 12; x >= 0; x--)
    {
        if(x%2 == 1)
        {
            result = result + 2*digit[x];
        }
        else
        {
            result = result + digit[x];
        }
    }
    printf("%li\n", result);
    printf("%i\n", digit[0]);
    printf("%li\n", result%10);

    if((result)%10 == 0 && digit[0] == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }*/
}
