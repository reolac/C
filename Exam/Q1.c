#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char firstName [80];
  char surName [80];
  int age;
  float feet;
  
  printf("What is your first name? ");
  
  scanf("%80s", &firstName);
  
  printf("\n\nWhat is your surname? ");
  
  scanf("%80s", &surName);
  
  printf("\n\nHow old are you? ");
  
  scanf("%d", &age);
  
  printf("\n\nHow tall are you in feet? ");
  
  scanf("%f", &feet);
  
  printf("\n\n--------------------------------------------------------------------------");
  
  printf("\nYour name is %s %s, you are %d years old and you are %.1f feet tall", &firstName, &surName, age, feet);
  
  printf("\n--------------------------------------------------------------------------\n");
  
  system("PAUSE");	
  return 0;
}
