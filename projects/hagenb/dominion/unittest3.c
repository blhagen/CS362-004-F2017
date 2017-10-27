/***************************************************************************************
** Author: Brook Hagen
** Date: 10/22/17
** Course: CS362 SEII
** Description: Unit test #3 for Assignment #3

**	Include the following in your makefile:
**	
**	unittest1: unittest3.c dominion.o rngs.o
**		gcc -o unittest3 -g unittest3.c dominion.o rngs.o $(CFLAGS)
***************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>			//for random number generation

//set PRINT_OUT to 0 to remove print statements from output
#define PRINT_OUT 1

//Test Method

int main() {
	int i; 				// counter,
	int count;			//count = card counter
	int j;				//j = 0 to MAX_DECK
	int pile;			// pile == 0 (hand); == 1 (deck); == 2 (discard)
	int newCard = 0;			//chosen card that is added to hand, deck, or discard
	int seed = 500;
	int numPlayer = 2;			// players = 2 - 4
	int p, newGame;		//p = # players, newGame = initializeGame
	

	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, 
		village, baron, great_hall};
	struct gameState G;
	//int maxHandCount;
	
	//this works
	printf("----------------- TESTING fullDeckCount():-----------------\n\n");
	
	#if (PRINT_OUT ==1)
	printf("Test #1: For Players 1 - 4, set all card counts to zero:\n\n");
	#endif

	for (p = 0; p < MAX_PLAYERS; p++)
	{
		for (i = 0; i <= 25; i++) 
		{
			G.handCount[p] = 0;
			G.deckCount[p] = 0;
			G.discardCount[p] = 0;
			count = 0;
			#if (PRINT_OUT ==1)
				printf("Player %d, card %i: count = %d, expected = %d\n", p+1, i+1, count, fullDeckCount(p, i, &G));
			#endif
			assert(count == fullDeckCount(p, i, &G)); //check that count and fullDeckCount both = 0

		}
	}
	#if (PRINT_OUT ==1)
	printf("\nTest #2: Fill up the deck with 3 cards of each type. Place remaining cards in alternating deck and discard.\n\n");
	#endif

	newGame = initializeGame(numPlayer, k, seed, &G);	//initialize new game for 2 players
	for (p = 0; p < MAX_PLAYERS; p++)
	{
		//maxHandCount = 0;
		//count = 0;
		for (i = 0; i <= 25; i++) 
		{
			G.handCount[p] = 0;
			G.deckCount[p] = 0;
			G.discardCount[p] = 0;
			count = 0;

			//fill up the deck
			for (j = 0; j < MAX_DECK; j++)
			{
				//select a card from the supply
				newCard = rand() % 25;
				if (newCard == i) 
				{
					count++;
				}

				//put card in one of the three piles: hand, deck, or discard
				pile = rand() % 3;

				//put into the hand
				if (pile == 0)
				{
					G.hand[p][G.handCount[p]] = newCard;
					G.handCount[p]++;
				}

				//put into the deck
				else if (pile == 1)
				{
					G.deck[p][G.deckCount[p]] = newCard;
					G.deckCount[p]++;
				}

				//put into the discard pile
				else if (pile == 2)
				{
					G.discard[p][G.discardCount[p]] = newCard;
					G.discardCount[p]++;
				}
			}


			#if (PRINT_OUT ==1)
			printf("Player %d: fullDeckCount = %d, expected deck count is %d.\n", p+1, fullDeckCount(p, i, &G), count);
			#endif

			assert(count == fullDeckCount(p, i, &G)); //check that count and fullDeckCount are the same
		
		}
		//printf("\t\t\tPlayer %d: fullDeckCount = %d, expected count is %d\n", p+1, fullDeckCount(p, i, &G), count);
	}

	printf("\n>>>>>>  Testing of fullDeckCount() complete. All tests passed! <<<<<<<\n\n");

	return 0;
}
