#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int number = 0;
  
  int lowest;
  
  int count = 0;
  
  int highest = 0;
  
  int sum = 0;
  
  int average = 0;
 
  while(1)
  {
   printf("Enter a positive number : ");
   scanf("%d", &number);
   if (number < 0)
   printf("*** Error! No negatives ***\n");
   else
   {
       count++;
       sum = sum + number;
       if (number < lowest && number > 0)
             lowest = number;
       if (number > highest)
             highest = number;
       if (number == 0)
       {
          average = sum / count;
          printf("\n\nTotal is : %d", sum);
          printf("\nAverage is : %d", average);
          printf("\n");
          system("PAUSE");	
          return 0;
       }
   }
 }
}
