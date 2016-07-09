#include <stdio.h>
#include <stdlib.h>

char** create2DArray();

void insertHorizontally();

void insertVertically();

void insertDiagonally();

void printArray();

int main(int argc, char *argv[])
{
  int height = 20;
  int width = 40;
  
  char** myArray = create2DArray(height, width);
  
  insertHorizontally("apple", myArray, 5, 5);
  
  insertVertically("orange", myArray, 10, 10);
  
  insertDiagonally("pears", myArray, 10, 30);

  printArray(myArray, height, width);
  
  free(myArray);
  
  system("PAUSE");	
  return 0;
}

void insertHorizontally(char* word, char** array, int x, int y)
{
 int i;
 for (i = 0; i <= sizeof(word); i++)
 {
  array[x][y] = *word++;
  x++;
 }
}

void insertVertically(char* word, char** array, int x, int y)
{
 int i;
 array[x][y] = *word++;
 y++;
 for (i = 0; i <= sizeof(word); i++)
 {
  array[x][y] = *word++;
  y++;
 }
}

void insertDiagonally(char* word, char** array, int x, int y)
{
 int i;
 for (i = 0; i <= sizeof(word); i++)
 {
  array[x][y] = *word++;
  x++;
  y++;
 } 
}

void printArray(char ** array, int width, int height)
{
 int r, c;
 for (r = 0; r < width; r++)
 {
  for (c = 0; c < height; c++)
  {
  printf("%c", array[r][c]);
  }
  printf("\n");
 }
}

char **create2DArray(int rows, int cols)
{
 int i, j;
 char **array = (char **) malloc(sizeof(char *) * rows);
 for (i = 0; i < rows; i++)
     array[i] = (char *) malloc(sizeof(char) * cols); 
 for (i = 0; i < rows; i++)
     for (j = 0; j < cols; j++)
         array[i][j] = '.';
 return array;
}
