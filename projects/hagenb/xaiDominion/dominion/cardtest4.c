/***************************************************************************************
** Author: Brook Hagen
** Date: 10/22/17
** Course: CS362 SEII
** Description: card test #4 for Assignment #3
**	int adventurerCard(struct gameState *state, int currentPlayer, int drawntreasure, int cardDrawn, int z) 

**	Include the following in your makefile:
**	
**	cardtest4: cardtest4.c dominion.o rngs.o
**		gcc -o cardtest4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)
***************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "adventurer"

void pass(int actual, int result)
{
	if (actual == result)
	{
		printf("PASS\n");
	}
	else
		printf("FAIL\n");
}

int main() 
{
	int golds, silvers, coppers;			//counters
	int testGolds, testSilvers, testCoppers;
	int seed = 500;
	int numPlayers = 2;
	int thisPlayer = 0;
	int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// ----------- TEST 1: verify that two cards are drawn --------------
	printf("TEST 1: Verify that two cards are drawn and added to hand\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(steward, choice1, choice2, choice3, &testG, handPos, &bonus);

	//G.drawntreasure = 2;
	G.handCount[thisPlayer] =+2;

	printf("\tHand count = %d, expected %d\t", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
	pass(testG.handCount[thisPlayer], G.handCount[thisPlayer]);


	// ----------- TEST 1: verify treasure count --------------
	printf("\nTEST 2: Verify that treasure count is equal.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));
	cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

	golds = fullDeckCount(thisPlayer, 6, &G);
	silvers = fullDeckCount(thisPlayer, 5, &G);
	coppers = fullDeckCount(thisPlayer, 4, &G);

	testGolds = fullDeckCount(thisPlayer, 6, &testG);
	testSilvers = fullDeckCount(thisPlayer, 5, &testG);
	testCoppers = fullDeckCount(thisPlayer, 4, &testG);

	printf("Golds = %d, expected = %d\t", golds, testGolds);
	pass(golds, testGolds);
	printf("Silvers = %d, expected = %d\t", silvers, testSilvers);
	pass(silvers, testSilvers);
	printf("Coppers = %d, expected = %d\t", coppers, testCoppers);
	pass(coppers, testCoppers);
	

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	return 0;
}