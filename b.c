#include<stdio.h>

int main() /*Program ProgB*/
{
     /*DECLARCATION_BLOCK*/
     int a, b, c;
     float d, e;
     char f;
     /*CODE_BLOCK*/
     scanf("%i", &a);
     scanf("%i", &b);
     if(a > b)
     {
          printf("%c", 'A');
     }
     else
     {
          printf("%c", 'B');
     }
     printf("\n");
     scanf("%f", &d);
     e = d * 2.300000;
     printf("%f", e);
     printf("\n");
     scanf("%c", &f);
     printf("%c", f);
     printf("\n");
}/*End of Program*/
