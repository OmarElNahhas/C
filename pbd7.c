/*
This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main()
{

    //a = 97, z = 122
    //0 = 48, 9 = 57
    char encodedMsg[] = "1223451721";
    int length = strlen(encodedMsg);
    int numeralMsg[length];
    int firstNumber = encodedMsg[0]-48;
    int counter;

    if(firstNumber != 0)
    {
        counter = 1;
    }
    else
    {
        printf("Invalid message, can't start with a 0!");
        return 1;
    }


    for(int i = 0; i < length-1; i++)
    {
        numeralMsg[i] = encodedMsg[i]-48;
        numeralMsg[i+1] = encodedMsg[i+1]-48;
        int sum = numeralMsg[i]*10 + numeralMsg[i+1];
        if(sum <= 26)
        {
            counter++;
        }
    }
    printf("Number of possibilities: %i", counter);
}
