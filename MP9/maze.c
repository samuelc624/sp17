/*The first program creates the maze by scanning the file and using malloc to allocate memory. We then used fgetc to store the characters into a 2D array.
The destroyMaze function just frees a bunch of variables and pointers and stuff. The printMaze function increments through the array and prints out the
characters. And the solveMazeManhattanDFSHelper is to check each coordinate above, below, and to the sides. The solveMazeManhattanDFS is used to check if there
is a path in the respective directions and returns 1 if there are any solutions.
*/


#include <stdio.h>
#include <stdlib.h>
#include "maze.h"


/*
 * createMaze -- Creates and fills a maze structure from the given file
 * INPUTS:       fileName - character array containing the name of the maze file
 * OUTPUTS:      None
 * RETURN:       A filled maze structure that represents the contents of the input file
 * SIDE EFFECTS: None
 */
maze_t * createMaze(char * fileName)
{
    char c;
    char advaith[10];
    FILE *fp;
    fp = fopen(fileName, "r");
    maze_t *maze = malloc(sizeof(maze_t));
    fscanf(fp, "%d %d",&maze->height, &maze->width);

    maze->cells = malloc(maze->height * sizeof(char*));
    int i;
    for(i = 0; i< maze->height; i++){
      maze->cells[i] = malloc(maze->width*sizeof(char));
    }
    int j;
    for (i=0; i<maze->height;i++){
      fgets(advaith,10,fp); //gets rid of \n from maze.txt
      for (j=0; j<maze->width;j++){

        c = fgetc(fp);  //reads char from text file and stores to cell array
        maze->cells[i][j] = c;
        if(c==START){
          maze->startColumn = j;
          maze->startRow = i;
        }
        if(c==END){
          maze->endColumn = j;
          maze->endRow = i;
        }
      }
    }

    fclose(fp);
  return maze;
}


/*
 * destroyMaze -- Frees all memory associated with the maze structure, including the structure itself
 * INPUTS:        maze -- pointer to maze structure that contains all necessary information
 * OUTPUTS:       None
 * RETURN:        None
 * SIDE EFFECTS:  All memory that has been allocated for the maze is freed
 */
void destroyMaze(maze_t * maze)
{
  int i;
  for (i=0; i<maze->height; i++){
    free(maze->cells[i]);
  }
  free(maze->cells);//frees all allocated memory
  free(maze);
  return;

}

/*
 * printMaze --  Prints out the maze in a human readable format (should look like examples)
 * INPUTS:       maze -- pointer to maze structure that contains all necessary information
 *               width -- width of the maze
 *               height -- height of the maze
 * OUTPUTS:      None
 * RETURN:       None
 * SIDE EFFECTS: Prints the maze to the console
 */
void printMaze(maze_t * maze)
{
  int rows = maze->height;
  int cols = maze->width;
  int i,j;
  for(i=0; i<rows; i++){
    for(j=0; j<cols; j++){
      printf("%c",  (maze->cells)[i][j]);
    }
    printf("\n");
  }

}

/*
 * solveMazeManhattanDFS -- recursively solves the maze using depth first search,
 * INPUTS:               maze -- pointer to maze structure with all necessary maze information
 *                       col -- the column of the cell currently beinging visited within the maze
 *                       row -- the row of the cell currently being visited within the maze
 * OUTPUTS:              None
 * RETURNS:              0 if the maze is unsolvable, 1 if it is solved
 * SIDE EFFECTS:         Marks maze cells as visited or part of the solution path
 */

 int solveMazeManhattanDFSHelper(maze_t * maze, int col, int row)
 {
   int cols = maze->width;
   int rows = maze->height;
   if(col<0||row<0){
     return 0;
   }
   if(col>=cols||row>=rows){
     return 0;
   }
   if(maze->cells[row][col]=='%'){//returns maze unsolvable if statement is true
     return 0;
   }
   if(maze->cells[row][col]=='.'){//returns maze unsolvable if statement is true
     return 0;
   }
   if(maze->cells[row][col]=='~'){//returns maze unsolvable if statement is true
     return 0;
   }
   if(maze->cells[row][col]=='S'){//returns maze unsolvable if statement is true
     return 0;
   }
   if(maze->cells[row][col]=='E'){//returns maze solvable if statement is true
    // maze->cells[maze->startRow][maze->startColumn] = 'S';
     //maze->cells[maze->endRow][maze->endColumn] = 'E';
     return 1;
   }
   if(maze->cells[row][col]!='S'){
   maze->cells[row][col] = '.';
}
   if(solveMazeManhattanDFSHelper(maze, (col-1),row)==1){//checks to the left
     return 1;
   }
   if(solveMazeManhattanDFSHelper(maze, (col+1), row)==1){//checks to the right
     return 1;
   }
   if(solveMazeManhattanDFSHelper(maze, col, (row-1))==1){//checks above
     return 1;
   }
   if(solveMazeManhattanDFSHelper(maze, col, (row+1))==1){//checks below
     return 1;
   }
   if(maze->cells[row][col]!='S'){

   maze->cells[row][col] = '~';
}   return 0;
 }


 int solveMazeManhattanDFS(maze_t * maze, int col, int row) //checks if there is a valid path in all directions and fixes testcase 3
 {
   int a = solveMazeManhattanDFSHelper(maze, col -1 , row);
   int b = solveMazeManhattanDFSHelper(maze, col +1 , row);
   int c = solveMazeManhattanDFSHelper(maze, col , row-1);
   int d = solveMazeManhattanDFSHelper(maze, col , row+1);
   return a || b || c || d;

 }
