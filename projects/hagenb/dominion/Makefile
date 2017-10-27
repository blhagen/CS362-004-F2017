#Brook Hagen
# CS362 Fall 2017
# 
# Commands: 1) make all <Enter>
#	    2) playdom <int>

CFLAGS = -Wall -std=c99 -lm -fpic -ftest-coverage -fprofile-arcs

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard cardtest1 cardtest2 cardtest3 cardtest4 unittest1 unittest2 unittest3


# Unit test commands:
#sample from class:
#testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
#	gcc -o testUpdateCoins -g testUpdateCoins.c dominion.o rngs.o $(CFLAGS)

#Card unit tests for Assignment 3:

cardtest1: cardtest1.c dominion.o rngs.o interface.o
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o interface.o
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o interface.o
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o interface.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

#Unit tests for Assignment 3:
unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

# Create .out file for unit tests:
# Command: make unittestresults.out <Enter>
unittestresults.out: cardtest4.c unittest1.c unittest2.c unittest3.c unittest4.c dominion.c rngs.o interface.o
	echo "Results for unit tests: " > unittestresults.out

	# echo "testUpdateCoins.c" >> unittestresults.out
	# gcc -o testUpdateCoins testUpdateCoins.c -g dominion.c rngs.o interface.o $(CFLAGS)
	# ./testUpdateCoins >> unittestresults.out
	# gcov -b dominion.c >> unittestresults.out

# outpostCard
	echo "cardtest1.c" >> unittestresults.out
	gcc -o cardtest1 cardtest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

# gardensCard
	echo "cardtest2.c" >> unittestresults.out
	gcc -o cardtest2 cardtest2.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

# smithyCard
	echo "cardtest3.c" >> unittestresults.out
	gcc -o cardtest3 cardtest3.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

# adventurer card
	echo "cardtest4.c" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

# handCard
	echo "unittest1.c" >> unittestresults.out
	gcc -o  unittest1 unittest1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

# gameIsOver
	echo "unittest2.c" >> unittestresults.out
	gcc -o  unittest2 unittest2.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

# fullDeckCount
	echo "unittest3.c" >> unittestresults.out
	gcc -o  unittest3 unittest3.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

# getCost
	echo "unittest4.c" >> unittestresults.out
	gcc -o  unittest4 unittest4.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out


clean:
	rm -f *.o playdom.exe playdom player player.exe cardtest1 cardtest1.exe cardtest2 cardtest2.exe cardtest3 cardtest3.exe cardtest4 cardtest4.exe unittest1 unittest1.exe unittest2 unittest2.exe unittest3 unittest3.exe unittest4 unittest4.c *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittestresults.out
