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
	
    srand(time(NULL));
	
	printf("Card Test: Adventurer...\n");


	
	for (i = 0; i < TEST_NUMBER; i++) {
		gameInit = initializeTestGame(k, player, &state);
		memcpy(&stateTest, &state, sizeof(struct gameState));			
		if(gameInit == 0){
			cardPlay = playAdventurer(player, &state);
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
	game->hand[player][game->handCount[player]] = adventurer;


	return 0; 
	
}

int testCard(int player, struct gameState *game, struct gameState *gameTest){
	int i, card1, card2, treasure1, treasure2;

	for (i = 0; i < game->handCount[player]; i++) {
		card1 = game->hand[player][i];
		if (card1 == copper || card1 == silver || card1 == gold)
			treasure1++;
	}
	
	for (i = 0; i < game->handCount[player]; i++) {
		card2 = gameTest->hand[player][i];
		if (card2 == copper || card2 == silver || card2 == gold)
			treasure2++;
	}

	if ((treasure1 - treasure2) > 0 || (treasure1 - treasure2) < 3 ){
		printf("Success- %d additional treasure cards.\n", (treasure1 - treasure2));
	}else{
		printf("Fail - %d additional treasure cards.\n", (treasure1 - treasure2));
	}



	//verify more cards in test state hand than original hand
	if (gameTest->handCount[player] < game->handCount[player]){
		printf("Success - Additional cards added.\n");
	}else{
		printf("fail - No cards added");
	}

	return 0;
}




