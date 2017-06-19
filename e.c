#include<stdio.h>

int main() /*Program ProgV*/
{
     /*DECLARCATION_BLOCK*/
     int integer, i;
     /*CODE_BLOCK*/
     scanf("%i", &integer);
     if(integer <= 5 || integer >= 12)
     {
          printf("%i", integer);
     }
     printf("%f", 35.000000);
     printf("\n");
     /*for control vars*/
     register int _by;
     static int _true=(1==1);
     for (integer = (-1); _by =  (-1), (integer - (-5))*(_by >0) - (_by<0/_true) <=0; integer += _by)
     {
          printf("%i", integer);
          printf("\n");
     }
     i = -1;
     for (integer = (i * i * i); _by =  (i * i * i * i * i), (integer - (i * i * (i + i + i + i + i) ))*(_by >0) - (_by<0/_true) <=0; integer += _by)
     {
          printf("%i", integer);
          printf("\n");
     }
}/*End of Program*/
