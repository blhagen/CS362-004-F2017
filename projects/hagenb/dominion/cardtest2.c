/***************************************************************************************
** Author: Brook Hagen
** Date: 10/22/17
** Course: CS362 SEII
** Description: card test #2 for Assignment #3
**	gardendsCard() 

**	Include the following in your makefile:
**	
**	cardtest2: cardtest2.c dominion.o rngs.o
**		gcc -o cardtest2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)
***************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "gardens"

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
	int seed = 500;
	int val;
	int numPlayers = 2;
	int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	printf("\nTest: calling gardensCard will return -1.\n");

	// copy the game state to a test case
	memcpy(&testG, &G, sizeof(struct gameState));

	//call cardEffect, so that this will work whether function is separated out or not
	val = cardEffect(gardens, choice1, choice2, choice3, &testG, handPos, &bonus);

	printf("\tgardensCard() return value = %d, expected = %d\t", val, -1);
	pass(val, -1);

	assert(val == -1);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


	return 0;
}