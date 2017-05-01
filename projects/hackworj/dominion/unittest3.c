#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>




void my_assert(int b, char* s) {
  if (!b) {
    printf ("ASSERTION FAILURE: %s\n", s);
  }
}

int main(){
//isGameOver() test
  printf("Testing function: isGameOver()\n");

  // Setup

  struct gameState G;
  G.supplyCount[province] = 1;
  G.supplyCount[copper] = 1;
  G.supplyCount[silver] = 1;
  G.supplyCount[gold] = 1;

  // Game should not be over:

  my_assert(!isGameOver(&G)," game should not be over!");

  G.supplyCount[gold] = 0;
  my_assert(!isGameOver(&G),"game should not be over!");

  G.supplyCount[silver] = 0;
  my_assert(!isGameOver(&G),"game should not be over!");

  // Game should be over:

  my_assert(isGameOver(&G),"game should be over!");
  G.supplyCount[copper] = 0;

  // Game should not be over:

  G.supplyCount[silver] = 1;
  my_assert(~isGameOver(&G)," game should not be over!");

  // Game should be over:

  G.supplyCount[province] = 0;
  my_assert(isGameOver(&G),"game should  be over!");
  
  
  return 0;

}