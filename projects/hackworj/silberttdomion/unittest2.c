#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>




void my_assert(int b, char* s) {
  if (!b) {
    printf ("ASSERTION FAILURE: %s\n", s);
  }
}

//gainCard() test
int main () {

	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int count, supply, flag, player = 0;

	printf ("Unit test for gainCard Function.\n");
	int test;
	test = initializeGame(1, k, 1, &state);
	
	//test supply pile is empty or card not used
	printf ("Testing supply pile is empty\n");
	flag = 1;
	state.supplyCount[adventurer] = 0;
	gainCard(adventurer, &state, flag, player);
	
	my_assert(test == -1 , "bug! - return not -1");
	my_assert(state.supplyCount[adventurer] == 0, "bug! adventure card not 0 ");
	
	//test flag == 1, gain card to deck
	printf ("Testing card to deck\n");
	state.supplyCount[adventurer] = 10;
	supply = state.supplyCount[player];
	count = state.deckCount[player];
	
	test = gainCard(adventurer, &state, flag, player);
	
	my_assert(test == 0 , "bug! retun not 0");
	my_assert(state.deck[player][ state.deckCount[player] ] = adventurer, "wrong deckCount");
	my_assert(state.deckCount[player] == (count + 1), "wrong  deckCOunt");
	my_assert(state.supplyCount[player] == (supply - 1), "wrong supplyCount");
	
	//test flag == 2, gain card to hand
	printf ("Testing card to hand\n");	
	flag = 2;
	supply = state.supplyCount[adventurer];
	count = state.handCount[player];
	
	test = gainCard(adventurer, &state, flag, player);
	
	my_assert(test == 0 , "bug!");
	my_assert(state.deck[player][ state.handCount[player] ] = adventurer, "wrong ");
	my_assert(state.handCount[player] == (count + 1), "wrong hand count");
	my_assert(state.supplyCount[player] == (supply - 1), "wrong supplyCount!");
	
	//test flag == 0, gain card to discard 
	printf ("Testing card to discard\n");	
	flag = 0;
	supply = state.supplyCount[adventurer];
	count = state.discardCount[player];
	
	test = gainCard(adventurer, &state, flag, player);
	
	my_assert(test == 0 , "bug!");
	my_assert(state.deck[player][ state.discardCount[player] ] = adventurer, "Wrong !");
	my_assert(state.discardCount[player] == (count + 1), "wrond discard!");
	my_assert(state.supplyCount[player] == (supply - 1), "wrong supply");

	printf ("All test Okay.\n");
	return 0;

}