#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

int power(int getal, int lengte);

int main (void)
{
    int a[] = {1, 2, 3, 4, 5};
    int size_a = (sizeof(a) / sizeof(int));
    int som = 1;
    for(int i = 0; i < size_a; i++)
    {
       for(int j = 0; j < size_a; j++)
/*
Eerste for loop is bijvoorbeeld bij a[1] = 2. De for loop i vermenigvuldigt elke iteratie weer met de gehele a[] dankzij for loop j.
voorbeeld: 2*1 * 2*2 * 2*3 * 2*4 * 2*5 == 2^5 *(1*2*3*4*5). Maar omdat de het getal in de i'de index zelf niet mee mag tellen, a[1] = 2 in dit geval (zie opdr 28-7-2019),
is het 2^6*(1*3*4*5), dus deel je door 2^6 (grootte van array+1) in dit geval.
*/
       {
           som = som * a[i]*a[j];
       }
      //output naar gebruiker
       if(i == 0)
       {
           printf("[%i, ", som/power(a[i], size_a));  // som/getal^size_a+1
       }
       else if(i == size_a - 1)
       {
           printf("%i]\n",som/power(a[i], size_a));
       }
       else{
        printf("%i, ", som/power(a[i], size_a));
       }
       //^^output naar gebruiker

       som = 1;
    }
    return 0;
}

int power(getal, lengte)
{
    int resultaat = 1;
       for(int counter = 0; counter <= lengte; counter++)
       {
           resultaat = resultaat*getal;
       }
       return resultaat;
}



//# [3, 2, 1] [2*1, 3*1, 3*2]
//# alles vermenigvuldigen behalve degene waar hij nu is
//# dus
