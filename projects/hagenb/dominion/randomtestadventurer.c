/***************************************************************************************
** Author: Brook Hagen
** Date: 10/22/17
** Course: CS362 SEII
** Description: random test - Adventurer Card - for Assignment #4
**	int adventurerCard(struct gameState *state, int currentPlayer, int drawntreasure, int cardDrawn, int z) 

**	Include the following in your makefile:
**	
**	randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
**		gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
***************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

#define TESTCARD "adventurer"

int pass(int actual, int result)
{
	if (actual == result)
	{
		//printf("PASS\n");
		return 1;
	}
	else
		//printf("FAIL\n");
		return 0;
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
	//randomly produce seed number between 0 and 10.
	int h = rand() % 5;
	return h;
}

/************************************************************************************
  Function: getBonus
  Parameters: none
  Returns: int b
  Description:
  Calling the getBonus() function will select a random number between 1 and 10,
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
	srand(time(NULL));				//get random seed every run
	int i;						//counters
	int golds, silvers, coppers;	//coin counters
	int testGolds, testSilvers, testCoppers;
	int seed;
	int num_tests = 10; //10000;			//run the test 10,000 times
	int numPlayers;
	int thisPlayer;
	//int bonus = getBonus();

	int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};
	
	// initialize a game state and player cards
	numPlayers = getNumPlayers();
	seed = getSeed();
	thisPlayer = getThisPlayer(numPlayers);
	initializeGame(numPlayers, k, seed, &G);

	//time the tests
	clock_t t1, t2, totalT;

	printf("----------------- Random Test for Card: %s ----------------\n", TESTCARD);

	//start timers for test 1 and both tests together
	t1 = clock();
	totalT = clock();

	for (i = 0; i < num_tests * 10000; i++)
	{
		// ----------- TEST 1: verify that two cards are drawn --------------
		if (i == 0)
			printf("TEST 1: Verify that two cards are drawn and added to hand\n\n");

		numPlayers = getNumPlayers();
		seed = getSeed();
		thisPlayer = getThisPlayer(numPlayers);
		bonus = getBonus();
		handPos = getHandPos();

		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		
		//adventurerCard(&G, thisPlayer, 2, 1, 1);	
		cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

		// //G.drawntreasure = 2;
		// G.handCount[thisPlayer] =+ 2;

		
		if (pass(testG.handCount[thisPlayer], G.handCount[thisPlayer]==0))
			printf("\tTest %d failed: Hand count = %d, expected %d.", i, testG.handCount[thisPlayer], G.handCount[thisPlayer]);
		//printf("Number of players is %d, seed is %d, thisPlayer is %d, bonus is %d\n", numPlayers, seed, thisPlayer, bonus);
	}

	t1 = clock() - t1;
	double t1_taken = ((double)t1)/CLOCKS_PER_SEC; 	//Time in seconds
	printf("\n Test 1 time: %f.\n", t1_taken);

	printf("\n\t>> Test #1 is COMPLETE. <<\n");

	//start timer for test #2
	t2 = clock();

	//initializeGame(numPlayers, k, seed, &G);

	for (i = 0; i < num_tests; i++)
	{
		// // ----------- TEST 2: verify treasure count --------------

		if (i == 0)
			printf("\nTEST 2: Verify that treasure count is equal.\n");

		numPlayers = getNumPlayers();
		seed = getSeed();
		thisPlayer = getThisPlayer(numPlayers);
		bonus = getBonus();
		handPos = getHandPos();
		// copy the game state to a test case
		memcpy(&testG, &G, sizeof(struct gameState));
		
		cardEffect(steward, choice1, choice2, choice3, &testG, handPos, &bonus);

		golds = fullDeckCount(thisPlayer, 6, &G);
		silvers = fullDeckCount(thisPlayer, 5, &G);
		coppers = fullDeckCount(thisPlayer, 4, &G);

		testGolds = fullDeckCount(thisPlayer, 6, &testG);
		testSilvers = fullDeckCount(thisPlayer, 5, &testG);
		testCoppers = fullDeckCount(thisPlayer, 4, &testG);

		if (pass(golds, testGolds) == 0)
			printf("Test %d failed: Golds = %d, expected = %d\n", i, golds, testGolds);
		if (pass(silvers, testSilvers) == 0)
			printf("Test %d failed: Silvers = %d, expected = %d\n", i, silvers, testSilvers);
		if (pass(coppers, testCoppers) == 0)
			printf("Test %d failed: Coppers = %d, expected = %d\n", i + 1, coppers, testCoppers);
		
	}
	
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
