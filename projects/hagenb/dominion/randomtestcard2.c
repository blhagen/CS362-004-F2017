/***************************************************************************************
** Author: Brook Hagen
** Date: 10/22/17
** Course: CS362 SEII
** Description: random test #2 for Assignment #4
**	smithyCard(struct gameState *state, int currentPlayer, int handPos) 

**	Include the following in your makefile:
**	
**	randomtestcard2: randomtestcard2.c dominion.o rngs.o
**		gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
***************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

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

/************************************************************************************
  Function: getNumPlayers
  Parameters: none
  Returns: int n, the number of players for the game
  Description:
  Calling the getNumPlayers() function will select the number of players for the
  game, at random, between 2 and 4.
************************************************************************************/
int getNumPlayers()
{
	//randomly produce number of players between 2 and 4
	int n = (rand() % 3) + 2;
	return n;
}

/************************************************************************************
  Function: getSeed
  Parameters: none
  Returns: int s
  Description:
  Calling the getSeed() function will select a random number between 1 and 5000,
  which will be the seed number for the initializeGame() function.
************************************************************************************/
int getSeed()
{
	//randomly produce seed number between 1 and 5000.
	int s = rand() % 5001;
	return s;
}

/************************************************************************************
  Function: getThisPlayer(int numPlayer)
  Parameters: int number of players
  Returns: int p - the player of concern (thisPlayer)
  Description:
  Calling the getThisPlayer() function will select a random player from the current,
  number of players, which will be used to verify the discard function.
************************************************************************************/
int getThisPlayer(int n)
{
	//randomly select player based on number of players
	int p = (rand() % n);
	return p;
}

/************************************************************************************
  Function: getHandPos
  Parameters: none
  Returns: int h
  Description:
  Calling the getHandPos() function will select a random number between 0 and 4,
  which will represent the hand position of a particular card. Note that a hand has
  between 1 and 5 cards at positions 0 - 4.
************************************************************************************/
int getHandPos()
{
	//randomly produce number between 0 and 4.
	int h = rand() % 5;
	return h;
}

/************************************************************************************
  Function: getBonus
  Parameters: none
  Returns: int b
  Description:
  Calling the getBonus() function will select a random number between 0 and 10,
  which will represent coin bonus.
************************************************************************************/
int getBonus()
{
	//randomly produce seed number between 0 and 10.
	int b = rand() % 11;
	return b;
}

int main() 
{
	//seed the random number generator
	srand(time(NULL));
	int i;			//counters
	int seed;
	int num_tests = 10; //10000;			//run the test 10,000 times

	int numPlayers;
	int thisPlayer;
	int handPos, choice1 = 0, choice2 = 0, choice3 = 0, bonus;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	// initialize a game state and player cards
	numPlayers = getNumPlayers();
	seed = getSeed();
	thisPlayer = getThisPlayer(numPlayers);
	bonus = getBonus();
	handPos = getHandPos();
	initializeGame(numPlayers, k, seed, &G);

	//time the tests
	clock_t t1, t2, totalT;

	printf("----------------- Random Test for Card: %s ----------------\n", TESTCARD);

	//start timers for test 1 and both tests together
	t1 = clock();
	totalT = clock();

	//all the functions here are working
	for (i = 0; i < (num_tests); i++)
	{
		// ----------- TEST 1: outpostPlayed flag is set --------------
		if (i == 0)
		// ----------- TEST 1: verify that 3 cards were drawn --------------
		printf("\nTest #1: verify that three cards were drawn.\n");

		numPlayers = getNumPlayers();
		seed = getSeed();
		thisPlayer = getThisPlayer(numPlayers);
		bonus = getBonus();
		handPos = getHandPos();

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));

		//call cardEffect, so that this will work whether function is separated out or not
		cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);

		printf("\tHandCount for this player: %d\n", testG.handCount[thisPlayer]+1);
		printf("\tCards drawn = %d, expected = %d\t", testG.handCount[thisPlayer]+1 - 5, 3);
		pass(testG.handCount[thisPlayer]+1 - 5, 3);

		printf("Number of players is %d, seed is %d, thisPlayer is %d, bonus is %d, handPos is %d\n", numPlayers, seed, thisPlayer, bonus, handPos);
	}

	//get the execution time and print it:
	t1 = clock() - t1;
	double t1_taken = ((double)t1)/CLOCKS_PER_SEC; 	//Time in seconds
	printf("\n Test 1 time: %f.\n", t1_taken);

	printf("\n\t>> Test #1 is COMPLETE. <<\n");
	
	t2 = clock();

	for (i = 0; i < num_tests; i++)
	{

	// ----------- TEST 2: verify that card at handPos is discarded -------------- //
		// Function signature for discardCard():
		//	discardCard(handPos, currentPlayer, state, 0);
  			
		if (i == 0)
			printf("\nTest #2: calling smithy() will trigger the discardCard() function.\n");

		numPlayers = getNumPlayers();
		seed = getSeed();
		thisPlayer = getThisPlayer(numPlayers);
		bonus = getBonus();
		handPos = getHandPos();
		
		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));

		//call cardEffect, so that this will work whether function is separated out or not
		cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus);
		
		//this lastCard is working for the test case.
		//need to get last card for control case    03Nov17 16:14
		//int lastCard = numHandCards(&testG);
		//printf("\tThe last card is at position %d\n", lastCard);
		printf("\tThe card at the last handPos should be discarded, ie, == -1\n");
		printf("\tCard at handPos %d = %d, expected = %d\t", handPos, testG.hand[thisPlayer][handPos], -1);
		pass(testG.hand[thisPlayer][handPos], -1);

		for (handPos = 0; handPos <= testG.handCount[thisPlayer]; handPos++)
		{
			printf("\t\tCard at position %d is ID %d\n", handPos, testG.hand[thisPlayer][handPos]);
		}

		printf("\n\n");
	}

	//get the execution time and print it:
	t2 = clock() - t2;
	double t2_taken = ((double)t2)/CLOCKS_PER_SEC; 	//Time in seconds
	printf("\n Test 2 time: %f.\n", t2_taken);

	printf("\n\t >> Test #2 is COMPLETE. << \n");

	//get the execution time and print it:
	totalT = clock() - totalT;
	double total_taken = ((double)totalT)/CLOCKS_PER_SEC; 	//Time in seconds
	printf("\n Total testing time: %f.\n", total_taken);

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

	

	return 0;
}