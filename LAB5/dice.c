//Function for generating three d6 rolls
#include "dice.h"
#include <stdio.h>

void roll_three(int* one, int* two, int* three){
  *one = rand() % 6 +1;
  *two = rand() % 6 +1;
  *three = rand() % 6 +1;
  return;
}
