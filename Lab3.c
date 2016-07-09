/*
-----------------------------------------------------------------
Author: Michael Smith
Program Title: Scrambler
Purpose: Input a string and scramble the characters per character
Date: 7/3/2014
Version: 15
-----------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char input [256] = " "; //array(string) to store the keyboard input
  char cipher [256] = " "; //array(string) to store the cipher code
  char target; //character which is targetted to be replaced
  char replacement; //character which the target is to be replaced by
  int i; //counter for elements of the input array(string)
  int j; //counter for elements of the cipher array (string)
  int l; //counter for printing out the cipher
  
  printf("\n------------------------\n");
  printf("WELCOME TO THE SCRAMBLER\n"); //prints the welcome message
  printf("------------------------\n \n");
  
  printf("Please enter your string : ");
  fgets(input, 256, stdin); //asks user to input values to be saved to the input array(string)
  printf("\nWord is : %s\n\n", input); //prints out the input array(string)
      
  while (1) //infinite loop only exitable if the target == q
  { 		
  		int flag = 0; //counts the equality of the replacement elements resets to 0 after every count
  		int flag2 = 0; //counts the equality of the target elements resets to 0 after every count
  		int k = 0; //counts the amount of elements resets to 0 after every count
  			   
  		printf("Target is : ");
  	 	scanf("%c", &target, "\n"); //asks use for input to be saved to the target char 
		getchar(); //checks to save the char as a char
				
		if (target == 'q') //if q is entered into the target input this code will run if not it will skip
		{
			printf("\nSCRAMBLED STRING IS : %s", input); //prints out the input array(string)
			printf("\nScramble key -");	
			        
			for(l = j-1; l >= 0;l--)
			{ //deducts 1 from the total length of the cipher array(string) then runs from that number and deducts until it reaches 0
            	printf("%c", cipher[l]); //prints an element of the cipher key then loops
            }
            
        	printf("\n\n");
			
			break; //exits the infinite while loop which ends the program
		}  
					 	 	
		printf("Replace with : ");
  		scanf("%c", &replacement, "\n"); //asks user to input values to be saved to the replacement char 
		getchar(); //checks to save the char as a char 				
  		
		for  (i = 0; i < sizeof(input); i++) //sets i to 0 then increments i until it reaches the total size of the array(string)
		{ //cycles through the array(string)
			if (input [i] == replacement) //if an element(char) in the array is equal to the char stored in replacement  
			{
			flag = 1; //flag equality is set to 1 (something stored is equal to something you are trying to replace)
			}			
		}
		
		for (i = 0; i < sizeof(input); i++) //sets i to 0 then increments i until it reaches teh total size of the array(string)
		{ //cycles through the array(string)
			if (input [i] == target) //if an element(char) in the array is equal to the char stored in target
			{
				flag2 = 1; //flag equality is set to 1 (something stored is equal to something you are trying to replace)
			}
		}
				
		if (flag == 0) //if the flag equality is equal to 0 (something stored is not equal to something you are trying to replace)
		{
			for (i = 0; i < sizeof(input); i++) //sets i to 0 then increments i until it reaches the total size of the array(string)
			{ //cycles through the array(string)
			 	if (input[i] == target) //if an element(char) in the array is equal to the char stored in target
			 	{
				    input[i] = replacement; //the element(char) in the array is replaced by the char stored in replacement
				    k++; //counts how many times an element is changed
				}
			}		 	
		}			
			
		if (k >= 1) //if an element in the array was changed
		{
			printf("\nReplacing %c with %c\n", target, replacement); //prints what values are being replaced and what with
			cipher [j] = replacement; //replacement is stored to the cipher array(string)
			j++; //j is incremented by 1 to cycle through the array
			cipher [j] = target; //target is stored to the cipher array(string
			j++; //j is incremented by 1 to cycle through the array
			cipher [j] = ' '; //a space is stored in the array to indicate that, that is the cipher code for that change 
			j++; //j is incremented by 1 to cycle through the array					
		}
		
		if (flag == 1 && flag2 == 1) //if the replacement and the target is equal to the what's in the string
			printf("\nError : %c already exists in the string!\n", replacement); //print out that the element you are trying to replace exists						
		if (flag == 1 && flag2 == 0) //if the replacement is equal to what is in the string but the target does not equal what is in the string
			printf("\nError : %c does not exist in the string!\n", target); //prints out that the element does not exist in the string
			printf("Word is : %s \n\n" , input); //prints out an update of the word before the loop runs again
  }
	//this code will only run after q is inputted into target and the break sequence runs to break the infinite while loop
	system("PAUSE"); //pauses the program "Press any key to continue
	return 0; //closes the program returning a value of 0
}
