#include "dominion.h"
#include <string.h>
#include <stdio.h>




void my_assert(int b, char* s) {
  if (!b) {
    printf ("ASSERTION FAILURE: %s\n", s);
  }
}

//whosTurn() test

int main () {

  int g, t;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

		   
	printf ("Unit test for whosTurn Function.\n");
  struct gameState G;
  
  g = initializeGame(4, k, 1, &G);

  t = whoseTurn(&G);
  printf ("whoseTurn(&G) = %d\n", t);
  my_assert(t == 0, "whosTurn failed");
  
  return 0;
}