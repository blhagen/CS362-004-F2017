/***************************************************************************************
** Author: Brook Hagen
** Date: 10/22/17
** Course: CS362 SEII
** Description: Unit test #4 - getCost(int) for Assignment #3

**	Include the following in your makefile:
**	
**	unittest1: unittest4.c dominion.o rngs.o
**		gcc -o unittest4 -g unittest4.c dominion.o rngs.o $(CFLAGS)
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

//Test Method for getCost():
//	Using switch statement to mirror the actual function.
int main() {
	int i;					// counter which represents the card number
	int price;				// cost of each card, as returned by getCost()

	printf("----------------- TESTING getCost(): -----------------\n");


	//16Oct17 06:55
	//r = initializeGame(numPlayer, k, seed, &G);
	#if (PRINT_OUT ==1)

		printf("Test #1: Testing card numbers outside of range, eg, < 0 and > 26.\n");
		for (i = -3; i < 0; i++)
		{
			price = getCost(i);
			printf("\tgetCost() for %d = %d, expected %d\n", i, price, -1);
			assert(price == -1);
		}
		for (i = 27; i < 30; i++)
		{
			price = getCost(i);
			printf("\tgetCost() for %d = %d, expected %d\n", i, price, -1);
			assert(price == -1);
		}

	#endif


	#if (PRINT_OUT ==1)

		printf("\nTest #2: Testing values of each card, hard-coded vs. return value from getCost().\n");
		for (i = 0; i < 27; i++) 
		{

			price = getCost(i);

			switch(i) 
			{
				case curse:
					printf("\tgetCost() = %d, expected %d\n", price, 0);
					assert(price == 0);
					break;

				case estate:
					printf("\tgetCost() = %d, expected %d\n", price, 2);
					assert(price == 2);
					break;

				case duchy:
					printf("\tgetCost() = %d, expected %d\n", price, 5);
					assert(price == 5);
					break;

				case province:
					printf("\tgetCost() = %d, expected %d\n", price, 8);
					assert(price == 8);
					break;

				case copper:
					printf("\tgetCost() = %d, expected %d\n", price, 0);
					assert(price == 0);
					break;

				case silver:
					printf("\tgetCost() = %d, expected %d\n", price, 3);
					assert(price == 3);
					break;

				case gold:
					printf("\tgetCost() = %d, expected %d\n", price, 6);
					assert(price == 6);
					break;

				case adventurer:
					printf("\tgetCost() = %d, expected %d\n", price, 6);
					assert(price == 6);
					break;

				case council_room:
					printf("\tgetCost() = %d, expected %d\n", price, 5);
					assert(price == 5);
					break;

				case feast:
					printf("\tgetCost() = %d, expected %d\n", price, 4);
					assert(price == 4);
					break;

				case gardens:
					printf("\tgetCost() = %d, expected %d\n", price, 4);
					assert(price == 4);
					break;

				case mine:
					printf("\tgetCost() = %d, expected %d\n", price, 5);
					assert(price == 5);
					break;

				case remodel:
					printf("\tgetCost() = %d, expected %d\n", price, 4);
					assert(price == 4);
					break;

				case smithy:
					printf("\tgetCost() = %d, expected %d\n", price, 4);
					assert(price == 4);
					break;

				case village:
					printf("\tgetCost() = %d, expected %d\n", price, 3);
					assert(price == 3);
					break;

				case baron:
					printf("\tgetCost() = %d, expected %d\n", price, 4);
					assert(price == 4);
					break;

				case great_hall:
					printf("\tgetCost() = %d, expected %d\n", price, 3);
					assert(price == 3);
					break;

				case minion:
					printf("\tgetCost() = %d, expected %d\n", price, 5);
					assert(price == 5);
					break;

				case steward:
					printf("\tgetCost() = %d, expected %d\n", price, 3);
					assert(price == 3);
					break;

				case tribute:
					printf("\tgetCost() = %d, expected %d\n", price, 5);
					assert(price == 5);
					break;

				case ambassador:
					printf("\tgetCost() = %d, expected %d\n", price, 3);
					assert(price == 3);
					break;

				case cutpurse:
					printf("\tgetCost() = %d, expected %d\n", price, 4);
					assert(price == 4);
					break;

				case embargo:
					printf("\tgetCost() = %d, expected %d\n", price, 2);
					assert(price == 2);
					break;

				case outpost:
					printf("\tgetCost() = %d, expected %d\n", price, 5);
					assert(price == 5);
					break;

				case salvager:
					printf("\tgetCost() = %d, expected %d\n", price, 4);
					assert(price == 4);
					break;

				case sea_hag:
					printf("\tgetCost() = %d, expected %d\n", price, 4);
					assert(price == 4);
					break;

				case treasure_map:
					printf("\tgetCost() = %d, expected %d\n", price, 4);
					assert(price == 4);
					break;
			}
			
		}
	#endif

		printf("\n>>>>>>  Testing of getCost() complete. All tests passed! <<<<<<<\n\n");

		return 0;
}