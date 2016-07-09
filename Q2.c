#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int grade;
  
  printf("Enter grade: ");
  
  
  scanf("%d", &grade);
  
  if (grade > 79)
     grade = 80;
     
  if (grade < 80 && grade > 69)
  {
   
     grade = 70;
     printf("FUCK THE KING");
     }
  
  if (grade < 70 && grade > 59)
     grade = 60;
     
  if (grade < 60 && grade > 49)
     grade = 50;

  if ( grade < 50 && grade > 39)
     grade = 40;

  if (grade < 40 && grade > 0)
     grade = 30;
     
     
  
  switch (grade)
  {
   case 80:
        {
        printf("Grade A");
        printf("YOU FUCKING SPAS");
        grade = 0;
        }
   
   case 70:
        {
        printf("Grade B");
        
        grade = 0;
        }
   case 60:
        {
        printf("Grade C");
        grade = 0;
        }
        
   case 50:
        {
        printf("Grade D");
        grade = 0;
        }
        
   case 40:
        {
        printf("Grade E");
        grade = 0;
        }
   
   case 30:
        {
        printf("Fail");
        grade = 0;
        }  
        }
  
  system("PAUSE");	
  return 0;
}
