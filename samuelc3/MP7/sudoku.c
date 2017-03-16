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
  for (k=0;k<9;k++){
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
  for (l=0; l<9; l++){
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

  assert(i>=0 && i<9);
  assert(j>=0 && j<9);
  // BEG TODO
  int n, m;
	int flag = 0;

	for(n=i-1; n<=i+1; n++){
	   for(m =j-1; m<=j+1; m++){
	       if(val == sudoku[n][m])
         {
		flag = 1;
	break;
	}
		}
	}
if(flag==1)
	return 1;
else
	return 0;

  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

  assert(i>=0 && i<9 && j>=0 && j<9);

  // BEG TODO

  if (is_val_in_3x3_zone(val, i, j, sudoku)==0 && is_val_in_col(val, j, sudoku)==0 && is_val_in_row(val, i, sudoku)==0){
    return 1;
  }
  else {return 0;}
  // END TODO
}

// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {
  int i,j,val;
  // BEG TODO.
  for (i=0; i<9; i++){
    for (j=0; j<9; j++){
      if (sudoku[i][j]==0){
        for(val=1;val<10;val++){
          if (is_val_valid(val, i, j, sudoku)==1){
            sudoku[i][j]=val;
            break;
          }
          else{
            continue;
          }
        }
        }
      else{
        continue;
      }
    }
  }
  return 0;
 // END TODO.
}

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
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
