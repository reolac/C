#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int numberOne;
  int numberTwo;
 
  printf("Number one: ");
  scanf("%d", &numberOne);
  
  printf("\nNumber two: ");
  scanf("%d", &numberTwo);
  
  int result = numberOne + numberTwo;
  
  printf("\nResult: %d\n", result);
  
  
  system("PAUSE");	
  return 0;
}
