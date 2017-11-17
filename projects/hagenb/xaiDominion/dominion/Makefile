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
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard smithyUnit cardtest4 smithyRandom randomtestadventurer


#Card unit tests for Assignment 5:
#sample from class:
#testUpdateCoins: testUpdateCoins.c dominion.o rngs.o
#	gcc -o testUpdateCoins -g testUpdateCoins.c dominion.o rngs.o $(CFLAGS)

#smithyCard
smithyUnit: smithyUnit.c dominion.o rngs.o interface.o
	gcc -o smithyUnit smithyUnit.c -g dominion.o rngs.o interface.o $(CFLAGS)

#adventurerCard
cardtest4: cardtest4.c dominion.o rngs.o interface.o
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

# Create .out file for unit tests:
# Command: make unittestresults.out <Enter>
unittestresults.out: smithyUnit.c cardtest4.c dominion.c rngs.o interface.o
	echo "Results for unit tests: " > unittestresults.out

# smithyCard
	echo "smithyUnit.c" >> unittestresults.out
	gcc -o smithyUnit smithyUnit.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./smithyUnit >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out

# adventurer card
	echo "cardtest4.c" >> unittestresults.out
	gcc -o cardtest4 cardtest4.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out


# Random tests for Assignment 5:
smithyRandom: smithyRandom.c dominion.o rngs.o
	gcc -o smithyRandom smithyRandom.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o interface.o $(CFLAGS)


# Create .out file for random tests:
# Command: make randomtestresults.out <Enter>
randomtestresults.out: smithyRandom.c randomtestadventurer.c dominion.c rngs.o interface.o
	echo "Results for random testing: " > randomtestresults.out

# smithyCard
	echo "smithyRandom.c" >> randomtestresults.out
	gcc -o smithyRandom smithyRandom.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./smithyRandom >> randomtestresults.out
	gcov -b dominion.c >> randomtestresults.out

# adventurerCard
	echo "randomtestadventurer.c" >> randomtestresults.out
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./randomtestadventurer >> randomtestresults.out
	gcov -b dominion.c >> randomtestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe smithyUnit smithyUnit.exe cardtest4 
	cardtest4.exe randomtestadventurer 
	randomtestadventurer.exe *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe 
	#unittestresults.out smithyRandom smithyRandom.exe 
