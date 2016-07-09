#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char *myString = "Oranges and Lemons"; 
  
  int i;
  
  
  for (i = 0; i < 18; i++)
  {
  
  switch (*myString)
  {
   default: printf("%c\n", *myString); break;
   
   case 'A': printf("%c - vowel\n", *myString); break;
   
   case 'a': printf("%c - vowel\n", *myString); break;
   
   case 'E': printf("%c - vowel\n", *myString); break;
   
   case 'e': printf("%c - vowel\n", *myString); break;
   
   case 'I': printf("%c - vowel\n", *myString); break;
   
   case 'i': printf("%c - vowel\n", *myString); break;
   
   case 'O': printf("%c - vowel\n", *myString); break;
   
   case 'o': printf("%c - vowel\n", *myString); break;
   
   case 'U': printf("%c - vowel\n", *myString); break;

   case 'u': printf("%c - vowel\n", *myString); break;
   
  }
  *myString++;
  }
  system("PAUSE");	
  return 0;
}
