#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int len(long long int number);
void digit_in_number(long long number, int length);


int main()
{
    //max 19 numbers, 64 bits
    long long number = 123456744355;
    long long result = (number/100)%10;
    int length = len(number);
    digit_in_number(number, length);
    printf("\nlength of integer: %i\n", len(number));

}

void digit_in_number(long long number, int length)
{
    int division = 10;
    for(int i = 0; i < length; i++)
    {
        long long int result = (number/division)%10;
        division = division*10;
        printf("digit %i: %lli\n", i, result);
    }
}



int len(long long int number)
{
    int counter;
    for(counter = 0; number > 0; counter++)
    {
        number = number/10;
    }
    return counter;
}
    /*int x;
    int i;
    printf("How many elements do you want in your array?: ");
    scanf("%d", &x);
    int array[x];
    for(i = 0; i < x; i++)
    {
       array[i] = i+1;
       if(i == 0){
        printf("[%d, ", array[i]);
       }
       else if(i == x-1){
        printf("%d]", array[i]);
       }
       else{
       printf("%d, ", array[i]);
       }
    }

    for(int i=0; i<5; i++){
    FILE *fpointer = fopen("testdocument.txt", "a");
    fprintf(fpointer, "\nTest123 en %f", pow(i,2));
    fclose(fpointer);
    }

    return 0;
*/
/*
int height;
    do
    {
        printf("Height: ");
        scanf("%i", &height);
        //printf("\n");
    } while(height < 1 || height > 8);

    for(int x = 1; x <= height; x++)
    {
        //spaces
        for(int y = height - x; y >= 0; y--)
        {
            printf(" ");
        }
        for(int z = 0; z < x; z++)
        {
            printf("#");
        }
        printf("  ");
        for(int z = 0; z < x; z++)
        {
            printf("#");
        }
        printf("\n");
    }
return 0;

*/
