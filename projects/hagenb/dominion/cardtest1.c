/***************************************************************************************
** Author: Brook Hagen
** Date: 10/22/17
** Course: CS362 SEII
** Description: card test #1 for Assignment #3
**	outpostCard (struct gameState *state, int currentPlayer, int handPos) 

**	Include the following in your makefile:
**	
**	cardtest1: cardtest1.c dominion.o rngs.o
**		gcc -o cardtest1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)
***************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "outpost"

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
	//int i, j;			//counters
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

	// ----------- TEST 1: outpostPlayed flag is set --------------
	printf("\nTest #1: verify that state->outpostPlayed is incremented.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	//call cardEffect, so that this will work whether function is separated out or not
	cardEffect(outpost, choice1, choice2, choice3, &testG, handPos, &bonus);

	//outpostCard(&G, thisPlayer, handPos)
	printf("\toutpost Played = %d, expected = %d\t", testG.outpostPlayed, 1);
	pass(testG.outpostPlayed,1);
	

	// ----------- TEST 2: card at handPos is discarded --------------
	printf("\nTest #2: calling outpostCard() will trigger the discardCard() function.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	//call cardEffect, so that this will work whether function is separated out or not
	cardEffect(outpost, choice1, choice2, choice3, &testG, handPos, &bonus);

	//outpostCard(&G, thisPlayer, handPos)
	printf("\tThe card at the current handPos should be discarded, ie, == -1\n");
	printf("\tCard at handPos %d = %d, expected = %d\t", handPos, testG.hand[thisPlayer][handPos], -1);
	pass(testG.hand[thisPlayer][handPos], -1);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}