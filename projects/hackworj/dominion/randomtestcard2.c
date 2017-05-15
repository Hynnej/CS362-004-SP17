#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_NUMBER 5

int initializeTestGame(int k[10], int player, struct gameState *game);
int testCard(int player, struct gameState *game, struct gameState *gameTest);

int main(){

	struct gameState state, stateTest;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
	int i, gameInit, cardPlay, test, player = 0;	
	int handPo = 0;
	
    srand(time(NULL));
	
	printf("Card Test: Council Room...\n");


	
	for (i = 0; i < TEST_NUMBER; i++) {
		gameInit = initializeTestGame(k, player, &state);
		memcpy(&stateTest, &state, sizeof(struct gameState));			
		if(gameInit == 0){
			cardPlay = playCouncil_Room(player, &stateTest, handPo);
			if(cardPlay == 0){
				test = testCard(player, &state, &stateTest);  
				if(test == 0)
					printf("TEST COMPLETE \n\n");
			}	
		}	
	}

	printf("Tests Complete\n");



	return 0;
}

int initializeTestGame(int k[10], int player, struct gameState *game){
	int players = rand() % 4;
	int seed = rand();		//pick random seed

	initializeGame(players, k, seed, game);	//initialize Gamestate

	//Initiate valid state variables
	game->deckCount[player] = rand() % MAX_DECK; 
	game->discardCount[player] = rand() % MAX_DECK;
	game->handCount[player] = rand() % MAX_HAND;
	game->hand[player][game->handCount[player]] = council_room;

	//1 in 3 chance of making empty deck 
	if (seed % 3 == 0) {
		game->deckCount[player] = 0;
	}	

	return 0; 
	
}

int testCard(int player, struct gameState *game, struct gameState *gameTest){
	if(game->handCount[player] == gameTest->handCount[player])
	{
		printf("Success - Number of cards in hand \n");
	}else{
		printf("Fail - Number of cards in hand \n");
	}

	if ((gameTest->deckCount[player] - 1) == game->deckCount[player]){
		printf("Success - number of cards in deck.\n");
	}else{
		printf("fail - number of cards in deck\n");
	}
	
	if ((gameTest->numBuys + 1) == game->numBuys){
		printf("Success - number of buys.\n");
	}else{
		printf("fail - number of buys.\n");
	}	



	return 0;
}