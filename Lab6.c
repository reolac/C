/*
-----------------------------------------------------------------
Author: Michael Smith
Program Title: Jackpot Dreams
Purpose: Simulates the lottery
Date: 24/3/2014
Version: 5
-----------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* get_lotto_draw();
void print_array(); // initalizes the functions
int find_matches();

int main(int argc, char *argv[])
{
    printf("\n---------------------------- \n");
    printf("  Project : Jackpot Dreams \n");
    printf("---------------------------- \n");
    srand (time(NULL)); // sets the seed
        
	int years;    
    int lottery [] = {5, 11, 15, 33, 42, 43};  
	int *numbers;	
	numbers = lottery; // stores the array in a pointer
	
	int oneMatch = 0;
	int twoMatches = 0;
	int threeMatches = 0;
	int fourMatches = 0;
	int fiveMatches = 0;
	int sixMatches = 0;	// counters for the amount of matches
   
	int *random;
    	
	printf("\n How many years to sleep? ");
    scanf ("%d", &years, "\n");
        
    printf("\n Ok. I will now play the lottery for %d years\n Sweet dreams...\n", years);
    printf("\n--------------------------------\n");   
    
    int yearsToPlay = years * 52;   
    
    int yearsPlayed = 0;
  	
	while (yearsToPlay != 0) // loops the draw
	{
          random = get_lotto_draw(); // stores the return of the function to a pointer
          int matches = find_matches(lottery, random); // calls the matches function and carries across 2 pointers
          yearsToPlay--;	
	      yearsPlayed++;
	
	      if (matches >= 6)	
	         sixMatches++;  
       	   
          if (matches >= 5)
             fiveMatches++;
       
          if (matches >= 4)
             fourMatches++;
       
          if (matches >= 3)
             threeMatches++;
       
          if (matches >= 2)
             twoMatches++;
    
          if (matches >= 1)
             oneMatch++; // increments matches depending on the amount
       
          if (sixMatches > 0)    
             break; // breaks the loop if you win
          
          matches = 0;
    }
    
    print_array(lottery); // calls the function to print the array carrying it over as a pointer
    
    yearsPlayed = yearsPlayed/52;    
    
    int newYear = 2014 + yearsPlayed;
    
    if (sixMatches > 0)  
        printf("\n\n Wake up Roger! It's the year %d. You've won the lottery!\n", newYear);
    else
        printf("\n\n Wake up Roger! It's the year %d\n", newYear);
    
    printf("\n---------------------------------\n");            
    printf("\n Matched 1 number %d times", oneMatch);
    printf("\n Matched 2 numbers %d times", twoMatches); 
    printf("\n Matched 3 numbers %d times", threeMatches);
    printf("\n Matched 4 numbers %d times", fourMatches); 
    printf("\n Matched 5 numbers %d times", fiveMatches);
    printf("\n Matched 6 numbers %d times\n\n", sixMatches); 
  
    system("PAUSE");	
    return 0;
}

int * get_lotto_draw() //Returns an array of six random lottery numbers 1-49 
{
    int i;
	int j;  
	
    static int randomNumbers[6];
      
    for  (i = 0; i < 6; i++)
	{             
       int flag = 1;
       int n = 0;    // holding value
       
       while (flag == 1)
       {       
           n = (rand()%49 + 1); // sets the value to be a random number between 1 - 49
           flag = 0;
           
     	   for (j = 0; j < i; j++)
     	   {
     	    	if (n == randomNumbers[j]) // if the holding value is equal to a number in the array it loops until it is not
     		    {
			       flag = 1;
     	    	}
           }     	
       }   
    randomNumbers[i] = n; // stores the number in the array
	}
  return randomNumbers;
}

void print_array(int * array) //print out the content of an array
{
    int i;
    printf(" Matched the lottery numbers");
    
	for (i = 0;  i < 6; i++)
        printf(" %d", *array++); // prints and increments through the pointer
} 

int find_matches(int * array1, int * array2) //returns number of matches between two arrays
{
    int i = 0;
    int j = 0;			
    
    int matches = 0;			
			
	if(*array1 == *array2) // if the lottery pointer equals the random pointer
         matches ++; // increment matches				
                		
   	for (i=0; i<6 ;i++) // loops to the end of the lottery pointer
	{  	               
    	for (j=0; j<6;j++) // loops to the end of the random pointer
		{    
            if(*array1 == *array2) 
                matches ++; // increments the amount of matches if both are equal
                
            *array2++; // iterates through the random pointer
         } 
        *array1++; // iterates through the lottery pointer
        *array2--;
        *array2--;
        *array2--;
        *array2--;
        *array2--;
        *array2--; // resets the random pointer back to the first value
   	}
    return matches;			
}
