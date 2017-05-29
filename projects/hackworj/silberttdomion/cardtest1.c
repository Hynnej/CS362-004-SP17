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

  printf("Card Test: Village...\n");

  // Setup

  struct gameState G;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  initializeGame(2, k, 10, &G);

  G.whoseTurn = 1;
  G.hand[1][0] = village;
  int handCount = G.handCount[1];
  int numActions = G.numActions;
  int deckCount = G.deckCount[1];
  int playedCount = G.playedCardCount;

  // Do something

  // playCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state)
  playCard(0, 0, 0, 0, &G);

  // Did something, now check it

  my_assert(G.handCount[1] == handCount, "Wrong number of cards in hand");
  my_assert(G.deckCount[1] == deckCount - 1, "Wrong number of cards in deck");
  my_assert(G.playedCardCount == playedCount + 1, "Wrong number of cards in played cards");
  my_assert(G.numActions == numActions + 1, "Wrong number of actions");
  return 0;
}