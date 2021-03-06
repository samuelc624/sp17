/*The first function checks if the selected element is on the sides of the matrix. It then checks if the neighbors are 1 and adds 1 to the count.
*updateboard copies the current board to another one and updates it to the next stage.
*The last function checks if the alive stay alive for the next stage.
*/




/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */

int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col)
{
	int* init = board;
	int* final = init + boardRowSize*boardColSize;
	int* current = init + row*boardColSize + col;            //corresponding pointer to value in array of row and col

	int alive = 0;



	if ((current+1) < final)                                //Checks all 8 cases for neighbors and first sees if they lie out of bound
	{                                                       //before accessing the values and checking if they are 1 (alive)
		if (*(current+1) == 1)
		{
			alive++;
		}
	}
	if ((current-1) >= init)
	{
		if (*(current-1) == 1)
		{
			alive++;
		}
	}
	if ((current+boardColSize) < final)
	{
		if (*(current+boardColSize) == 1)
		{
			alive++;
		}
	}
	if ((current-boardColSize) >= init)
	{
		if (*(current-boardColSize) == 1)
		{
			alive++;
		}
	}
	if ((current+boardColSize-1) < final && (current+boardColSize-1) >= init)
	{
		if (*(current+boardColSize-1) == 1)
		{
			alive++;
		}
	}
	if ((current+boardColSize+1) < final)
	{
		if (*(current+boardColSize+1) == 1)
		{
			alive++;
		}
	}
	if ((current-boardColSize+1) < final && (current-boardColSize+1) >= init)
	{
		if (*(current-boardColSize+1) == 1)
		{
			alive++;
		}
	}
	if ((current-boardColSize-1) >= init)
	{
		if (*(current-boardColSize-1) == 1)
		{
			alive++;
		}
	}
	return alive;                                                   //returns the # of alive cells
}
/*
 * Update the game board to the next step.
 * Input:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int* board, int boardRowSize, int boardColSize) {

int row=0;
int col=0;
int neighbors=0;
int locations=0;
int cellstatus=-1;


int maxsize=boardRowSize*boardColSize;
int oldboard[maxsize];
int i = 0;
for (i=0;i<=maxsize;i++){
	oldboard[i] = *(board+i);				//copies old board to dummy board
}

for (row=0; row<=boardRowSize; row++){
	for (col=0; col<=boardColSize; col++){
		locations=(boardColSize*row)+col;
		cellstatus=*(board+locations);
		neighbors=countLiveNeighbor(board, boardRowSize, boardColSize, row, col);     //does countLiveNeighbor function
		if (cellstatus==1 && (neighbors == 2 || neighbors == 3)){
			cellstatus = 1;
		}
		else if (cellstatus==0 && neighbors==3){
			cellstatus = 1 ;
		}
		else{
			cellstatus =0;
		}
	oldboard[locations]=cellstatus;
	}
}

for (i=0; i<=maxsize; i++){
	*(board+i) = oldboard[i];				//copipes dummy board to old board
}

}

/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */


int aliveStable(int* board, int boardRowSize, int boardColSize){

int maxsize=boardRowSize*boardColSize;
int oldboard[maxsize];
int i = 0;
for (i=0;i<=maxsize;i++){
	oldboard[i] = *(board+i);				//copies dummy board to the old board
}

int row=0;
int col=0;
int neighbors=0;
int locations=0;
int cellstatus=-1;
int change=0;
int alive;
for (row=0; row<=boardRowSize; row++){
	for (col=0; col<=boardColSize; col++){
		locations=(boardColSize*row)+col;
		cellstatus=oldboard[locations];

		neighbors=countLiveNeighbor(board, boardRowSize, boardColSize, row, col);			//does countLiveNeighbor function
		if (cellstatus==1 && (neighbors == 2 || neighbors == 3)){
			alive++;
		}
		else if (cellstatus==0 && neighbors==3) {
			change++;
			alive++;
		}
		else if (cellstatus==1 && (neighbors<2 || neighbors>3)) {
			change++;
		}
	}
}
if (change==0 || alive==0){
	return 1;
}
else{
	return 0;
}

}
