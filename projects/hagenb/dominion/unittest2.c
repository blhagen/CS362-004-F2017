/***************************************************************************************
** Author: Brook Hagen
** Date: 10/22/17
** Course: CS362 SEII
** Description: Unit test #2 for Assignment #3

**		--  isGameOver(struct gameState *state)  --

**	Include the following in your makefile:
**	unittest1: unittest2.c dominion.o rngs.o
**		gcc -o unittest2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

** Resources:
**		Example files provided by CS 362 instructor
**		https://lostechies.com/derekgreer/2011/03/14/effective-tests-a-unit-test-example/
**		http://www.dummies.com/programming/c/how-to-generate-random-numbers-in-c-programming/
***************************************************************************************/

#include "dominion.h"
#include "interface.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>			//for random number generation

//set PRINT_OUT to 0 to remove print statements from output
#define PRINT_OUT 1

//Test Method for isGameOver()
int main() {
	
	int i, j, r;			// i = supply counter; j = loop counter; r is for rand()

	int seed = 500;

	//set up counts for 2 player game
	int numPlayer = 2;
	int newGame;			//p = # players, newGame = initializeGame
	
	//set kingdom cards
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, 
		village, baron, great_hall};
	struct gameState G;
	
	printf("----------------- TESTING isGameOver(): -----------------\n");


	//16Oct17 06:55
	//r = initializeGame(numPlayer, k, seed, &G);
	#if (PRINT_OUT ==1)

		printf("Test #1: initialize all supply counts to 0. isGameOver should be True.\n");
		for (i = 0; i <= 25; i++) 
		{
			//printf("Supply for card %d is %d.\n", i, G.supplyCount[i]);
		}
		printf("\nisGameOver = %d, expected = %d\n\n", isGameOver(&G), 1);
	#endif
		assert(isGameOver(&G) == 1); //check that game is over when counts == 0

	#if (PRINT_OUT == 1)
		printf("Test#2: initialize new game with full counts for 2 players.\n");
		printf("isGameOver should be False.\n");
		newGame = initializeGame(numPlayer, k, seed, &G);	//initialize new game
		for (i = 0; i <= 25; i++) 
		{
			//printf("Supply for card %d is %d.\n", i, G.supplyCount[i]);
		}
		printf("\nisGameOver = %d, expected = %d\n\n", isGameOver(&G), 0);
	#endif
		assert(isGameOver(&G) == 0); //check that game is on when counts != 0

	#if (PRINT_OUT == 1)
		printf("Test#3: set province card count to 0. isGameOver should be True.\n");
		G.supplyCount[province] = 0;
		printf("Supply for card province is %d.\n", G.supplyCount[province]);
		printf("\nisGameOver = %d, expected = %d\n\n", isGameOver(&G), 1);
	#endif
		assert(isGameOver(&G) == 1); //check that game is over when province = 0

		memset(&G, 17, sizeof(struct gameState));	//clear game
	#if (PRINT_OUT == 1)
		printf("Test#4: initialize new game ans set each card supply = 1.\n");
		printf("isGameOver should be False.\n");
		newGame = initializeGame(numPlayer, k, seed, &G);	//initialize new game
		for (i = 0; i <= 25; i++) 
		{
			G.supplyCount[i] = 1;

			printf("Supply for card %d is %d.\n", i, G.supplyCount[i]);
		}
		printf("\nisGameOver = %d, expected = %d\n\n", isGameOver(&G), 0);
	#endif
		assert(isGameOver(&G) == 0); //check that game is on when counts > 0

		memset(&G, 17, sizeof(struct gameState));	//clear game
		newGame = initializeGame(numPlayer, k, seed, &G);	//initialize new game
	#if (PRINT_OUT == 1)
		printf("Test#5: In a loop that runs 300 times, randomly set three card\n"); 
		printf("supplies to empty. isGameOver should be True on each iteration.\n");
		for (j = 0; j < 300; j++) 
		{
			//set three stacks to = 0
			for (i = 0; i < 3; i++)
			{
				r = rand() % 25;	//generate random number between 0 and 24
				if (G.supplyCount[r] == 0)	//if count at r is already 0
				{
					i--;	//decrement i
				}
				else
					G.supplyCount[r] = 0;	//else, set the current card count to 0
			}

			/*** Uncomment the following for loop to see the counts for each card type */
			// for (i = 0; i <= 25; i++) 
			// {
			// 	printf("\tSupply for card %d is %d.\n", i, G.supplyCount[i]);
			// }

			printf("Try %d: isGameOver = %d, expected = %d\n", j+1, isGameOver(&G), 1);
			assert(isGameOver(&G) == 1); //check that game is over when three counts = 0
			memset(&G, 17, sizeof(struct gameState));	//clear game
			newGame = initializeGame(numPlayer, k, seed, &G);	//initialize new game
		}
		
	#endif

	printf("\n>>>>>>  Testing of isGameOver() complete. All tests passed! <<<<<<<\n\n");

	return 0;

}