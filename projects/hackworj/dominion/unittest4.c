#include "dominion.h"
#include <string.h>
#include <stdio.h>




void my_assert(int b, char* s) {
  if (!b) {
    printf ("ASSERTION FAILURE: %s\n", s);
  }
}

//getCost() test

int main () {
	int i, costTest;
	int cost[28] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, -1};
	
	  printf("Testing function: getCost()...\n");
	for(i = 0; i < 28; i++){
		costTest = getCost(i);
		my_assert(cost[i] == costTest, "cost is wrong");
	}
	
	return 0;

}

