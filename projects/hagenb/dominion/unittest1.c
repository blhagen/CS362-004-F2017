/***************************************************************************************
** Author: Brook Hagen
** Date: 10/22/17
** Course: CS362 SEII
** Description: Unit test #1 - handCard(int, struct) for Assignment #3

**	Include the following in your makefile:
**	
**	unittest1: unittest1.c dominion.o rngs.o
**		gcc -o unittest1 -g unittest1.c dominion.o rngs.o $(CFLAGS)
***************************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include "rngs.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//set PRINT_OUT to 0 to remove print statements from output
#define PRINT_OUT 1

//Test Method for handCard():
int main() {
	int i, j;					// counter
	int seed = 500;
	int numPlayer = 4;		// players = 2 - 4
	int newGame;			//initialize newGame
	//int maxBonus = 10;		//bonus cards max is 10
	//int p, r, handCount;	//p = # players, r = initializeGame, handcount = 0 - 5
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, 
		village, baron, great_hall};
	struct gameState G;
	int maxHandCount = 5;


	printf("----------------- TESTING handCard() -----------------\n");

	//16Oct17 06:55
	//r = initializeGame(numPlayer, k, seed, &G);
	#if (PRINT_OUT ==1)

		printf("\nTest #1: no cards in hand. The first card should be == 0.\n");
		for (i = 0; i < numPlayer; i++) 
		{
			G.handCount[i] = 0;
			printf("handCard() 1 for player %d is %d, expected %d.\n", i+1, G.hand[i][0], handCard(0, &G));
		}
	#endif
		assert(handCard(0, &G) == 0); //check that game is over when counts == 0

		newGame = initializeGame(numPlayer, k, seed, &G);
		//memset(&G, 17, sizeof(struct gameState));	//clear game
	

	#if (PRINT_OUT ==1)

		printf("\nTest #2: 5 cards in hand, with all cards being gold (#6).\n");
		for (i = 0; i < numPlayer; i++) 
		{
		// 	//printf("\nPlayer %d: \n", i+1);
		// 	//set each players hand to 5 cards
		// 	G.handCount[i] = maxHandCount;
		// 	//set every card in the players' hands to gold
		//i = 1;
			for (j = 1; j <= maxHandCount; j++)
			{
				G.hand[i][j] = gold;
				printf("Card %d for player %d is %d, expected %d.\n", j, i+1, G.hand[i][j], handCard(j, &G));
			}
			printf("Card %d for player %d is %d, expected %d.\n", j-1, i, G.hand[i][j-1], handCard(j-1, &G));
		}
	#endif	
		//assert(handCard(j-1, &G) == 6); //check that game is over when counts == 0


	memset(&G, 17, sizeof(struct gameState));	//clear game
	newGame = initializeGame(numPlayer, k, seed, &G);

	#if (PRINT_OUT ==1)

		printf("\nTest #3: 5 cards in hand, with all cards being treasure_map (#26).\n");
		for (i = 0; i < numPlayer; i++) 
		{
			// printf("\nPlayer %d: \n", i+1);
			//set each players hand to 5 cards
			G.handCount[i] = maxHandCount;
			//set every card in the players' hands to gold
			for (j = 1; j <= maxHandCount; j++)
			{
				G.hand[i][j] = treasure_map;
				printf("\tCard %d for player %d is %d, expected %d.\n", j, i+1, G.hand[i][j], handCard(j, &G));
			}
			printf("Card %d for player %d is %d, expected %d.\n", j-1, i, G.hand[i][j-1], handCard(j-1, &G));
		}
	#endif	
		assert(handCard(j-1, &G) == 26); //check that game is over when counts == 0


	memset(&G, 17, sizeof(struct gameState));	//clear game
	newGame = initializeGame(numPlayer, k, seed, &G);

	#if (PRINT_OUT ==1)

		printf("\n\nTest #4: 5 cards in hand.\n");
		printf("\tPlayer 1: cards 5, 6, 7, 8, 9)\n ");
		printf("\tPlayer 2: cards 6, 8, 10, 12, 14\n");
		printf("\tPlayer 3: cards 7, 10, 13, 16, 19)\n");
		printf("\tPlayer 4: cards 8, 12, 16, 20, 24)\n");

		
		for (i = 0; i < numPlayer; i++) 
		{
			printf("\nPlayer %d: \n", i+1);
			//set each players hand to 5 cards
			//G.handCount[i] = maxHandCount;
			//set every card in the players' hands 
			for (j = 1; j <= maxHandCount; j++)
			{
				G.hand[i][j] = ((i+1) * j) + 4;
				printf("\tCard %d for player %d is %d, expected %d.  ", j, i+1, G.hand[i][j], handCard(j, &G));
				if (G.hand[i][j] == handCard(j, &G))
					printf("PASS\n");
				else
					printf("FAIL\n");
			}
			printf("Card %d for player %d is %d, expected %d.", j-1, i+1, G.hand[i][j-1], handCard(j-1, &G));
			if (G.hand[i][j-1] == handCard(j-1, &G))
				printf("PASS\n");
			else
				printf("FAIL\n");
			
		}
	#endif	

	printf("\n>>>>>>  Testing of handCard() complete. All tests passed! <<<<<<<\n\n");

	return 0;

}
