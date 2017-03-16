/*The first function checks the row by incrementing the for loop and checking if the value is in the row. The second function checks the column to see if the
 *val is there. The 3x3 val check divides the i and j by three and checks the 3x3 array to see if the value is already there. If any of the values are in the
 *row/col/grid, it will return 1. The solver then checks to see if the val check is or not, filling in the space with the designated val. The print
 *function then goes through every value in the array and prints it out.
*/


#include "sudoku.h"

//-------------------------------------------------------------------------------------------------
// Start here to work on your MP7
//-------------------------------------------------------------------------------------------------

// You are free to declare any private functions if needed.

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);
  int k;
  int flag=0;
  // BEG TODO
  for (k=0;k<9;k++){          //goes through each row checking through val
    if (val==sudoku[i][k]){
      flag= 1;
      break;
    }
    else {
      flag= 0;
      continue;
    }
  }
if (flag==1){
  return 1;
}
else{
  return 0;
}
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);
  int l;
  int flag=0;
  // BEG TODO
  for (l=0; l<9; l++){            //goes through each column checking for val
    if (val==sudoku[l][j]){
      flag = 1;
      break;
    }
  else {
      flag=0;
      continue;
    }
  }
if (flag==1){
  return 1;
}
else{
  return 0;
}
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);


  // BEG TODO
int k, l;
k = (i/3)*3;    //sets k to be one side of grid
l = (j/3)*3;    //sets l to be one side of grid
int p,q;
int flag=0;
for (p=k;p<(k+3);p++){          //increments coordinate in grid
  for (q=l;q<(l+3);q++){
    if (sudoku[p][q]==val){
      flag++;
    }
  }
}
if (flag>0){
  return 1;
}
else{
  return 0;
}


  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);

  // BEG TODO
  if (is_val_in_3x3_zone(val, i, j, sudoku)==0 && is_val_in_row(val,i,sudoku)==0 && is_val_in_col(val, j, sudoku)==0){
    return 1;
  }
  else {return 0;}
  // END TODO
}

// Procedure: solve_sudoku
// Solve the given sudoku instance.

int solve_sudoku(int sudoku[9][9]) {

  int i,j,val;
  int flag1=0;
  int flag2=0;
  // BEG TODO.
  for (i=0;i<9;i++){
    for (j=0;j<9;j++){
      if (sudoku[i][j]>0){
        flag1++;
      }
    }
  }
if (flag1==81){
  return 1;
}

  for (i=0; i<9; i++){
    for(j=0; j<9; j++){
      if (sudoku[i][j]==0){
        for (val=1; val<10; val++){
          if (is_val_valid(val,i,j,sudoku)==1){     //if the val_valid is 1, then set the coordinate to val
            sudoku[i][j]=val;
            if(solve_sudoku(sudoku)){
              return 1;
            }
            sudoku[i][j]=0;
          }
        }
        return 0;
      }
  }

}

  // END TODO.
}

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;                               //prints out sudoku values 
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}
