/*The first function loads the input file and loads the tuple type, and overwrites the old coordinates if they overlap. If an element is 0, it should be deleted.
The gv_tuples function returns the element at corresponding row & column. set_tuples sets row & column, deletes 0 node at corresponding row and column,
finds the next location of the node (if the value already exists, overwrite the value), and creates a node if none is available. add_tuples adds the two matrices
by skipping over the 0+0 spaces in the matrix (returns NULL if impossible). mult_tuples multiplies the nodes in the same row of matrix. The last functions frees
all allocated memory.
*/

#include "sparsemat.h"

#include <stdio.h>
#include <stdlib.h>

void destroy_recurs(sp_tuples_node * headP);
/*
  This MP is meant to use a linked list as an efficient way of storing a matrix which
  contains mostly 0
*/
sp_tuples * load_tuples(char* input_file)
{

  FILE *creator = fopen(input_file, "r"); //opens the file to read
  sp_tuples * listS = malloc(sizeof(sp_tuples)); //alocates room for list
  int row = 0, col = 0, r, c;
  double v = 0;
  fscanf(creator, "%d %d", &row, &col); //sets up dimensions for matrix and other internals
  listS->m = row;
  listS->n = col;
  listS->tuples_head = NULL;
  listS->nz = 0;
  while(fscanf(creator, "%d %d %lf", &r, &c, &v) == 3) //loads matrix into linked list
  {
    set_tuples(listS, r, c, v);
  }
  return listS;
}



double gv_tuples(sp_tuples * mat_t,int row,int col)

{
  int totCol = mat_t->n;
  int headLoc = -1;
  sp_tuples_node * pCell = mat_t->tuples_head;  //node pointer to cell
  if(pCell != NULL)
  {
    headLoc = (pCell->row)*totCol + (pCell->col);   //if not NULL, headLoc equals the row*totCol + col
  }
  int goalLoc = row * totCol + col;
  while( pCell != NULL && headLoc < goalLoc)
  {
    pCell = pCell->next;        //pCell is the next node if not NULL and headLoc < goalLoc
    if(pCell != NULL)
    {
      headLoc = (pCell->row)*totCol + (pCell->col);
    }
  }
  if(pCell != NULL && (pCell->row == row && pCell->col == col))
  {
    return pCell->value;
  }
  return 0;
}



void set_tuples(sp_tuples * mat_t, int row, int col, double value)
{
  sp_tuples_node * pCell = mat_t->tuples_head;    //initialize pointers
  sp_tuples_node * needAdd = NULL;
  int totCol = mat_t->n;
  int goalLoc = row*totCol + col;
  int headLoc = -1;
  //int currLoc = 0;
  if(pCell != NULL)
  {
    headLoc = (pCell->row)*totCol + (pCell->col);  //same initialization
  }
  sp_tuples_node * cCell = NULL;
  if(value != 0)
  {

    if(mat_t->tuples_head == NULL || goalLoc < headLoc)
    {
      needAdd = malloc(sizeof(sp_tuples_node));   //allocate memory for node and
      needAdd->row = row;       //row
      needAdd->col = col;       //col
      needAdd->value = value;   //and value
      needAdd->next = mat_t->tuples_head;
      mat_t->tuples_head = needAdd;
      mat_t->nz = mat_t->nz + 1;
      return;
    }
    else if((row*totCol + col) == headLoc)
    {
      (mat_t->tuples_head)->value = value;    //value from tuples_head is equal to value
      //mat_t->nz = mat_t->nz + 1;
      return;
    }
    headLoc = (pCell->row)*totCol + (pCell->col);
    cCell = pCell->next;
    if(cCell != NULL)
    {
      headLoc = (cCell->row)*totCol + (cCell->col);
    }
    while(cCell != NULL && headLoc < goalLoc)
    {
      pCell = cCell;
      cCell = cCell->next;
      if(cCell != NULL)
      {
        headLoc = (cCell->row)*totCol + (cCell->col);
      }
    }
    /*while(cCell != NULL && pCell->col < col)
    {
      pCell = cCell;
      cCell = cCell->next;
      headLoc = (pCell->row)*totCol + (pCell->col);
    }*/
    if(cCell == NULL)
    {
      needAdd = malloc(sizeof(sp_tuples_node));
      needAdd->row = row;
      needAdd->col = col;
      needAdd->value = value;
      needAdd->next = NULL;
      pCell->next = needAdd;
      mat_t->nz = mat_t->nz + 1;
      return;

    }
    else if(headLoc == goalLoc)
    {
      pCell->value = value;
      return;
    }
    else if(headLoc > goalLoc)
    {
      needAdd = malloc(sizeof(sp_tuples_node));
      needAdd->row = row;
      needAdd->col = col;
      needAdd->value = value;
      needAdd->next = cCell;
      pCell->next = needAdd;
      mat_t->nz = mat_t->nz + 1;
      return;
    }

  }
  else        //if value = 0
  {
    if(mat_t->tuples_head == NULL || gv_tuples(mat_t,row,col) == 0)
    {
      return;
    }
    if((mat_t->tuples_head)->row == row && (mat_t->tuples_head)->col == col)
    {
      cCell = (mat_t->tuples_head)->next;
      free(mat_t->tuples_head);
      mat_t->tuples_head = cCell;
      mat_t->nz = mat_t->nz - 1;
      return;
    }
    cCell = pCell->next;
    while(cCell->row != row || cCell->col != col)
    {
      pCell = cCell;
      if(cCell->next == NULL)
      {
        return;
      }
      cCell = cCell->next;      //next in linked list
    }
    pCell->next = cCell->next;     //next in linked list for both Cell
    if(cCell != NULL)
    {
      mat_t->nz = mat_t->nz - 1;
    }
    free(cCell);        //free cCell from mem allocation
    return;
  }

}



void save_tuples(char * file_name, sp_tuples * mat_t)
{
  FILE *printer = fopen(file_name, "w");    //int file pointer
  int r = mat_t->m;
  int c = mat_t->n;
  fprintf(printer, "%d %d \n", r, c);
  sp_tuples_node * pCell = mat_t->tuples_head;
  int row, col;
  double value;
  while(pCell != NULL)    //if pCell isn't NULL, set all values from the file
  {
    row = pCell->row;
    col = pCell->col;
    value = pCell->value;
    fprintf(printer, "%d %d %lf \n", row, col, value);
    pCell = pCell->next;
  }
  fclose(printer);
  return;
}



sp_tuples * add_tuples(sp_tuples * matA, sp_tuples * matB)
{
  if(matA->n != matB->n || matA->m != matB->m)
  {
    return NULL;
  }
  sp_tuples * matC = malloc(sizeof(sp_tuples));
  matC->m = matA->m;
  //int r = matA->m;
  matC->n = matA->n;
  int c = matA->n;
  //int headLoc = ()
  int bR, bC;
  sp_tuples_node * headOri = matA->tuples_head;
  sp_tuples_node * bOri = matB->tuples_head;
  while(headOri != NULL)
  {
    set_tuples(matC, headOri->row, headOri->col, headOri->value);
    headOri = headOri->next;
  }
  headOri = matA->tuples_head;
  double aVal = 0, bVal = 0;
  int oriLoc = (headOri->row)*(c)+(headOri->col);
  int bLoc = (bOri->row)*(c)+(bOri->col);
  //int holder;
  //sp_tuples_node * headCop = matC->tuples_head;
  while(bOri != NULL)
  {
    bR = bOri->row;
    bC = bOri->col;
    bLoc = bR * c + bC;
    bVal = bOri->value;
    headOri = matC->tuples_head;
    while(headOri != NULL && oriLoc < bLoc)
    {
      //holder = headOri->value;

      if(headOri != NULL)
      {
        aVal = headOri->value;
        oriLoc = ((headOri->row)*(c))+(headOri->col);
      }
            headOri = headOri->next;
    }
    if(headOri != NULL && oriLoc == bLoc)
    {
      //aVal = headOri->value;
      set_tuples(matC, headOri->row, headOri->col, bVal + aVal);
    }
    else
    {
      set_tuples(matC, bR, bC, bVal);
    }
    bOri = bOri->next;
  }
	return matC;
}



sp_tuples * mult_tuples(sp_tuples * matA, sp_tuples * matB){
  if(matA->n != matB->m)
  {
    return NULL;
  }
  sp_tuples * matC = malloc(sizeof(sp_tuples));
  int iA = 0, jA = 0, jB = 0;
  double cVal = 0, bVal, aVal;
  matC->m = matA->m;
  matC->n = matB->n;
  sp_tuples_node * aNode = matA->tuples_head;
  sp_tuples_node * bNode = matB->tuples_head;
  while(aNode != NULL)
  {
    iA = aNode->row;
    jA = aNode->col;
    aVal = aNode->value;
    bNode = matB->tuples_head;
    while(bNode != NULL && bNode->row < jA)
    {
      bNode = bNode->next;
    }
    while(bNode != NULL && bNode->row == jA)
    {
      //iB = bNode->row;
      jB = bNode->col;
      bVal = bNode->value;
      cVal = bVal * aVal;
      set_tuples(matC, iA, jB, cVal);
      bNode = bNode->next;
    }
    aNode = aNode->next;
  }
  return matC;
}



void destroy_tuples(sp_tuples * mat_t)    //free all mem allocation
{
  destroy_recurs(mat_t->tuples_head);
  free(mat_t);
  return;
}

void destroy_recurs(sp_tuples_node * headP)   //recursively free mem allocation and destroy recursively
{
  if(headP->next == NULL)
  {
    free(headP);
    return;
  }
  else{
    destroy_recurs(headP->next);
    free(headP);
    return;
  }
}
