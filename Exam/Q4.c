#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int numberFrom;
  int numberToo;
  int jumpRate;

  printf("Enter Range from : ");
  
  scanf("%d", &numberFrom);
  
  printf("Enter Range too : ");
  
  scanf("%d", &numberToo);
  
  printf("Enter jump rate : ");
  
  scanf("%d", &jumpRate);
  
  printf("\nRange (%d to %d by %d) : ", numberFrom, numberToo, jumpRate);
  
  if (numberFrom <= numberToo)
  {
   while (numberFrom <= numberToo)
   {
    printf("%d ", numberFrom);
    numberFrom = numberFrom + jumpRate;
   }
  }
  
  else
  {
   while (numberToo <= numberFrom && numberToo >= 0)
   {
    printf("%d ", numberToo);
    numberToo = numberToo - jumpRate;
   }
  }
  printf("\n");
  
  system("PAUSE");	
  return 0;
}
