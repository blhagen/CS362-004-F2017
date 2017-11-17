/***************************************************************************************
** Author: Brook Hagen
** Date: 10/22/17
** Course: CS362 SEII
** Description: card test #3 for Assignment #3
**	smithyCard(struct gameState *state, int currentPlayer, int handPos) 

**	Include the following in your makefile:
**	
**	cardtest3: cardtest3.c dominion.o rngs.o
**		gcc -o cardtest3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)
***************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "smithy"

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
	//int i;			//counters
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

	// ----------- TEST 1: verify that 3 cards were drawn --------------
	printf("\nTest #1: verify that three cards were drawn.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	//call cardEffect, so that this will work whether function is separated out or not
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);

	printf("\tHandCount for this player: %d\n", testG.handCount[thisPlayer]+1);
	printf("\tCards drawn = %d, expected = %d\t", testG.handCount[thisPlayer]+1 - 3, 3);
	pass(testG.handCount[thisPlayer]+1 - 3, 3);
	

	// ----------- TEST 2: verify that card at handPos is discarded --------------
	printf("\nTest #2: calling smithy() will trigger the discardCard() function.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	//call cardEffect, so that this will work whether function is separated out or not
	cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
	
	printf("\tThe card at the last handPos (9) should be discarded, ie, == -1\n");
	printf("\tCard at handPos %d = %d, expected = %d\t", 9, testG.hand[thisPlayer][9], -1);
	pass(testG.hand[thisPlayer][9], -1);

	for (handPos = 0; handPos <= testG.handCount[thisPlayer]; handPos++)
	{
		printf("\t\tCard at position %d is ID %d\n", handPos, testG.hand[thisPlayer][handPos]);
	}

	printf("\n\n");

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	

	return 0;
}