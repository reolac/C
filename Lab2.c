#include <stdio.h>
#include <stdlib.h>

/*
Author: Michael Smith
Program Title: ChatBot
Purpose: Chatbot which reads from keyboard and converts values
Date: 7/02/2014
Version: 1
*/

int main(int argc, char *argv[]) 
{
  printf("------------ \n");
  printf("Chatbot v0.1 \n"); // prints the title
  printf("------------ \n");  
  printf("\n");  // new line
  
  printf("I am a chatbot \n");
  printf("You are a human \n"); // prints the introduction
  printf("I have five questions for you! \n");  
  printf("\n");
    
  printf("What is your first name? "); // prints the question
  char firstName [80]; // creates a variable to store the answer (array = man length)
  scanf ("%79s", &firstName, "\n"); // asks for the answer via scanf storesit in the created variable
    
  printf("What is your surname? "); // prints the quesiton
  char surName [80]; // creates a variable to store the answer (array = max length)
  scanf ("%79s", &surName, "\n");  // ask for the answer via scanf stores it in the created variable
  
  printf("What year were you born? "); // prints the question
  int dob; // creates a variable to store the answer
  scanf ("%d", &dob, "\n");  // ask for the answer via scanf stores it in the created variable
  
  printf("How tall are you in centimeters? "); // prints the question
  float height; // creates a variable to store the answer
  scanf ("%f", &height, "\n");  // ask for the answer via scanf stores it in the created variable
  
  printf("What is your weight in kilograms? "); // prints the question
  float weight; // creates a variable to store the answer
  scanf ("%f", &weight, "\n");  // ask for the answer via scanf stores it in the created variable

  int age = 2014 - dob; // converts data from dob into age by taking it away from the current year
  
  float feet = height * 0.0328; // converts centimeters into feet
  
  float pounds = weight * 2.20462; // converts weight into pounds
  
  printf("\n");
  
  printf("Your name is %s %s", firstName, surName); // prints out the answer for the names %s indicating the string variable
  printf(". You are about %d ", age);  // prints out the answer for the age %d for decimal value for ints
  printf("years old. You are about %.2f ", feet); // prints out the answer for feet %.2f for float values to 2 decimal points
  printf("feet tall and weigh about %.2f ", pounds); // prints out the answer for pounds %.2f for float values to 2 decimal points
  printf("pounds \n");
  
  
  system("PAUSE"); // stops the system in command line prompting you to press any key to close it, allows you to view the output
  	
  return 0;
}
