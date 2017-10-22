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
	int count, total;	//count = card counter
	int j;				//j = 0 to MAX_DECK
	int pile;			// pile == 0 (hand); == 1 (deck); == 2 (discard)
	int newCard = 0;			//chosen card that is added to hand, deck, or discard
	int seed = 500;
	int numPlayer = 2;			// players = 2 - 4
	int p, newGame;	//p = # players, newGame = initializeGame
	//int handCount, deckCount, discardCount; 
	// handcount = 1 to 5; deckCount, discardCount = 0 to MAX_DECK

	 int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, 
	 	village, baron, great_hall};
	struct gameState G;
	int maxHandCount;
	
	//this works
	printf("TESTING fullDeckCount():\n\n");
	
	printf("Test #1: For Players 1 - 4, set all card counts to zero:\n\n");
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

	printf("\nTest #2: Fill up the deck with 3 cards of each type. Place remaining cards in alternating deck and discard.\n\n");
	newGame = initializeGame(numPlayer, k, seed, &G);	//initialize new game for 2 players
	for (p = 0; p < MAX_PLAYERS; p++)
	{
		maxHandCount = 0;
		//count = 0;
		for (i = 0; i <= 25; i++) 
		{
			//G.handCount[p] = i;
			// G.hand[p][G.handCount[p]] = i;
			// printf("\t%d", G.hand[p][G.handCount[p]]);
			// G.deckCount[p] = i;
			// G.discardCount[p] = i;
			// count += 3;

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
			printf("\nPlayer %d: fullDeckCount = %d, expected deck count is %d.\n", p+1, fullDeckCount(p, i, &G), count);
			#endif

			assert(count == fullDeckCount(p, i, &G)); //check that count and fullDeckCount are the same

			//fill up the hand, then split cards between discard and deck
			// for (j = 0; j <= MAX_DECK; j++)
			// {
			// 	//choose any of the 25 cards 
			// 	newCard = rand() % 25;
			// 	printf("newCard number is %d\n", newCard);

			// 	if (newCard == i) 
			// 	{
			// 		//increment our count
			// 		printf("\tnewCard number is %d\n", newCard);
			// 		count++;
			// 		printf("\t\tCount is %d\n", count);
			// 	}

			// 	//put the card in hand, deck, or discard
			// 	pile = rand() % 3;

			// 	//add to hand
			// 	while (maxHandCount < 6) 
			// 	{
			// 		if (pile == 0)
			// 		{
			// 			G.handCount[p]++;
			// 			G.hand[p][G.handCount[p]] == newCard;
			// 			printf("\t\t\tplayer %d handcount is %d\n", p, G.handCount[p]);
			// 		}
			// 	}

			// }
			
		
		}
		//printf("\t\t\tPlayer %d: fullDeckCount = %d, expected count is %d\n", p+1, fullDeckCount(p, i, &G), count);

	}



		// //fill up the hand, then the equally split remaining 495 cards between the discard and deck
		// for (j = 0; j <= maxHandCount; j++) 
		// {
		// 	// while (j < maxHandCount)
		// 	// {
		// 		newCard = rand() % 25;				//get any card from the 25 available
		// 		if (newCard == i)
		// 		{
		// 			count ++;
		// 		}
		// 		printf("\tNewCard number is: %d.\n", newCard);
		// 		G.hand[p][G.handCount[p]] = newCard;	//add new card to the hand
		// 		// count++;							//increment the count
		// 	//}

		// 	// G.handCount[p] = 0;
		// 	// G.deckCount[p] = 0;
		// 	// G.discardCount[p] = 0;
		// 	// count = 0;
		// 	for (i = 0; i <= 25; i++)
		// 	{
				
		// 		#if (PRINT_OUT ==1)
		// 		printf("Player %d, card %i: count = %d, expected = %d\n", p+1, i+1, count, fullDeckCount(p, i, &G));
		// 		#endif
		// 		count = 0;
		// 	}
			
		// }
		//assert(count == fullDeckCount(p, i, &G)); //check that count and fullDeckCount both = 0
	
		// for (i = 0; i <= 25 ; i++)
		// {

		// }
		// for (handCount = 1; handCount <= maxHandCount; handCount++)
		// {
		// 	c++;
		// 	printf("\thandcount = %d, total count = %d\n", handCount, c);
		// 	for (deckCount = 0; deckCount <= 2; deckCount++)
		// 	{
		// 		c++;
		// 		printf("\t\tdeckCount = %d, total count = %d\n", deckCount, c);
		// 		for (discardCount = 0; discardCount <= 2; discardCount++)
		// 		{

		// 			#if (PRINT_OUT == 1)
		// 			printf("Test player %d with %d in hand, %d in deck, and %d in discard.\n", p, handCount, deckCount, discardCount);
		// 			#endif

		// 			memset(&G, 17, sizeof(struct gameState));			//clear game
		// 			newGame = initializeGame(numPlayer, k, seed, &G);	//new game
		// 			G.hand[p][handCount] = handCount;				//set card counts for newGame
		// 			G.deck[p][deckCount] = deckCount;				//  to the current loop count 
		// 			G.discard[p][discardCount] = discardCount;		//  for each card "pile"
		// 			val = fullDeckCount(p, c, &G);

		// 			#if (PRINT_OUT == 1)
		// 			printf("c = %d, count = %d\n", c, val);
		// 			#endif

		// 			//assert(c == val);
		// 		}
		// 	}
		//}

	printf("\n>>>>>>  Testing of fullDeckCount() complete. All tests passed! <<<<<<<\n\n");
}
/***************************************************************************************

//public void SomeTestForSomeFunction_ReturnsTrue() {
	//Arrange: create and set up a system under test (SUT), eg, a new game
	//eg, struct gameState* newGame() {
			//struct gameState* g = malloc(sizeof(struct gameState));
			//return g;
	}

	//Act: poke the system under test, usually by invoking a method. If the method 
	//returns something back to us, we collect the result to ensure it was correct.
	//If the method doesn't return anything, we want to check whether it produced the 
	//	expected side effect(s).
	

	//Assert: make the unit test pass or fail. Here, we check that the method's behavior
	//	is consistent with expectations.
	//eg,
	// Assert.IsTrue(XXXXXX);

}
***************************************************************************************/