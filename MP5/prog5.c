/*This part of the program begins with the set_seed function that starts the rand number generator function to be used to store random numbers into an array.
 *The game then starts and generates 4 random numbers and stores them into 4 variables.
 *make_guess function then starts and reads four inputs from user and checks/stores them into an array. The 4 random numbers are also stored into an array.
 *The next part reads the guesses from user and check to see if they match the solution array. If they do, the match array will be set to 1 to indicate a match.
 *After every guess, the program will print out the number of tries, the number of numbers correct and incorrect. At the end, the program will terminate.
 */

/*
 *
 * prog5.c - source file adapted from UIUC ECE198KL Spring 2013 Program 4
 *           student code -- GOLD VERSION by Steven S. Lumetta
 */


/*
 * The functions that you must write are defined in the header file.
 * Blank function prototypes with explanatory headers are provided
 * in this file to help you get started.
 */



#include <stdio.h>
#include <stdlib.h>

#include "prog5.h"


/*
 * You will need to keep track of the solution code using file scope
 * variables as well as the guess number.
 */

static int guess_number;
static int solution1;
static int solution2;
static int solution3;
static int solution4;


/*
 * set_seed -- This function sets the seed value for pseudorandom
 * number generation based on the number the user types.
 * The input entered by the user is already stored in the string seed_str by the code in main.c.
 * This function should use the function sscanf to find the integer seed value from the
 * string seed_str, then initialize the random number generator by calling srand with the integer
 * seed value. To be valid, exactly one integer must be entered by the user, anything else is invalid.
 * INPUTS: seed_str -- a string (array of characters) entered by the user, containing the random seed
 * OUTPUTS: none
 * RETURN VALUE: 0 if the given string is invalid (string contains anything
 *               other than a single integer), or 1 if string is valid (contains one integer)
 * SIDE EFFECTS: initializes pseudo-random number generation using the function srand. Prints "set_seed: invalid seed\n"
 *               if string is invalid. Prints nothing if it is valid.
 */
int
set_seed (const char seed_str[])
{
//    Example of how to use sscanf to read a single integer and check for anything other than the integer
//    "int seed" will contain the number typed by the user (if any) and the string "post" will contain anything after the integer
//    The user should enter only an integer, and nothing else, so we will check that only "seed" is read.
//    We declare
int seed;
char post[2];
//    The sscanf statement below reads the integer into seed.
int scanresult;
scanresult = sscanf (seed_str, "%d%1s", &seed, post);
if (scanresult==1)
{
  srand(seed);
  return 1;
}
else{
  printf("set_seed: invalid seed\n");
  return 0;
}
//    If there is no integer, seed will not be set. If something else is read after the integer, it will go into "post".
//    The return value of sscanf indicates the number of items read succesfully.
//    When the user has typed in only an integer, only 1 item should be read sucessfully.
//    Check that the return value is 1 to ensure the user enters only an integer.
//    Feel free to uncomment these statements, modify them, or delete these comments as necessary.
//    You may need to change the return statement below

}


/*
 * start_game -- This function is called by main.c after set_seed but before the user makes guesses.
 *               This function creates the four solution numbers using the approach
 *               described in the wiki specification (using rand())
 *               The four solution numbers should be stored in the static variables defined above.
 *               The values at the pointers should also be set to the solution numbers.
 *               The guess_number should be initialized to 1 (to indicate the first guess)
 * INPUTS: none
 * OUTPUTS: *one -- the first solution value (between 1 and 8)
 *          *two -- the second solution value (between 1 and 8)
 *          *three -- the third solution value (between 1 and 8)
 *          *four -- the fourth solution value (between 1 and 8)
 * RETURN VALUE: none
 * SIDE EFFECTS: records the solution in the static solution variables for use by make_guess, set guess_number
 */
void
start_game (int* one, int* two, int* three, int* four)
{
    //your code here
  *one = ((rand())%8)+1;        //set *one to random number
  *two = ((rand())%8)+1;        //set *two to random number
  *three = ((rand())%8)+1;      //set *three to random number
  *four = ((rand())%8)+1;       //set *four to random number
  guess_number = 1;             //flag guess_number
  solution1= *one;              //define solution1 to be value of random number
  solution2= *two;              //define solution2 to be value of random number
  solution3= *three;            //define solution3 to be value of random number
  solution4=*four;              //define solution4 to be value of random number

}

/*
 * make_guess -- This function is called by main.c after the user types in a guess.
 *               The guess is stored in the string guess_str.
 *               The function must calculate the number of perfect and misplaced matches
 *               for a guess, given the solution recorded earlier by start_game
 *               The guess must be valid (contain only 4 integers, within the range 1-8). If it is valid
 *               the number of correct and incorrect matches should be printed, using the following format
 *               "With guess %d, you got %d perfect matches and %d misplaced matches.\n"
 *               If valid, the guess_number should be incremented.
 *               If invalid, the error message "make_guess: invalid guess\n" should be printed and 0 returned.
 *               For an invalid guess, the guess_number is not incremented.
 * INPUTS: guess_str -- a string consisting of the guess typed by the user
 * OUTPUTS: the following are only valid if the function returns 1 (A valid guess)
 *          *one -- the first guess value (between 1 and 8)
 *          *two -- the second guess value (between 1 and 8)
 *          *three -- the third guess value (between 1 and 8)
 *          *four -- the fourth color value (between 1 and 8)
 * RETURN VALUE: 1 if the guess string is valid (the guess contains exactly four
 *               numbers between 1 and 8), or 0 if it is invalid
 * SIDE EFFECTS: prints (using printf) the number of matches found and increments guess_number(valid guess)
 *               or an error message (invalid guess)
 *               (NOTE: the output format MUST MATCH EXACTLY, check the wiki writeup)
 */
int make_guess (const char guess_str[], int* one, int* two, int* three, int* four)
{
//  One thing you will need to read four integers from the string guess_str, using a process
//  similar to set_seed
//  The statement, given char post[2]; and four integers w,x,y,z,
int w,x,y,z;                    //initialization
char post[2];

int scancheck;                                                                  //see below comments for functionality
int validity=0;
scancheck = sscanf (guess_str, "%d%d%d%d%1s", &w, &x, &y, &z, post);             //store guess string into w, x, y, z
if (scancheck==4 && 0<w && w<9 && 0<x&&x<9 && 0<y&&y<9 && 0<z&&z<9){             //checks if 4 integers and if they are >0 and <9
  validity=1;                                                                    // valid flag
}
else {
  validity=0;
}
//  will read four integers from guess_str into the integers and read anything else present into post
//  The return value of sscanf indicates the number of items sucessfully read from the string.
//  You should check that exactly four integers were sucessfully read.
//  You should then check if the 4 integers are between 1-8. If so, it is a valid guess
//  Otherwise, it is invalid.
//  Feel free to use this sscanf statement, delete these comments, and modify the return statement as needed
if (validity ==0)
{ printf("make_guess: invalid guess\n");                        //if guess is not an integer between 0-9, print invalid guess
  return 0;}
else{
                                                                  //calculates number of perfect and misplaced matches
int solutions[4];                                         //initialize solution array
solutions[0]= solution1;
solutions[1]= solution2;
solutions[2]= solution3;
solutions[3]= solution4;

int guesses[4];                                           //initialize guess array
guesses[0]=w;
*one = w;
guesses[1]=x;
*two = x;
guesses[2]=y;
*three = y;
guesses[3]=z;
*four = z;

int i=0;
int matches[4] = {0,0,0,0};
int misplaced[4] = {-1,-1,-1,-1};

if (solution1==w){                                        //if any of the solutions are equal to the guesses, change value of that variable in the perfect match array to 1
  matches[0]=1;
}
if (solution2==x){
  matches[1]=1;
}
if (solution3==y){
  matches[2]=1;
}
if (solution4==z){
  matches[3]=1;
}

int j = 0;

for (i=0; i<4;  i++)
{
  if (matches[i]==1){
    continue;
  }
  else {
    for (j=0; j<4; j++){
      if (guesses[i]==solutions[j] && matches[j]!=1 && misplaced[0] != j && misplaced[1] != j && misplaced[2] != j && misplaced[3] != j){
        misplaced[i]=j;
        break;
      }
      }
    }
}

int number_of_matches = 0;
int number_of_misplace = 0;
for (i=0;i<4;i++){
  if (matches[i]==1){             //checks array for # of correct guesses
    number_of_matches++;          //increments number of correct guesses by one
  }
  if (misplaced[i]>=0){           //checks array for number of incorrect guesses
    number_of_misplace++;         //number_of_misplace=number_of_misplace+1
  }
}
printf("With guess %d, you got %d perfect matches and %d misplaced matches.\n",guess_number,number_of_matches,number_of_misplace); // prints out result of guesses
guess_number++; //guess_number=guess_number+1
return 1;
}

}
