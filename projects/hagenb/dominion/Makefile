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

# runtests: testDrawCard 
# 	./testDrawCard &> unittestresults.out
# 	gcov dominion.c >> unittestresults.out
# 	cat dominion.c.gcov >> unittestresults.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard randomtestcard1 randomtestcard2 randomtestadventurer



# Random tests for Assignment 4:

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o interface.o $(CFLAGS)


# Create .out file for random tests:
# Command: make randomtestresults.out <Enter>
randomtestresults.out: randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.c rngs.o interface.o
	echo "Results for random testing: " > randomtestresults.out

# outpostCard
	echo "randomtestcard1.c" >> randomtestresults.out
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	gcov -b dominion.c >> randomtestresults.out

# smithyCard
	echo "randomtestcard2.c" >> randomtestresults.out
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out
	gcov -b dominion.c >> randomtestresults.out

# adventurerCard
	echo "randomtestadventurer.c" >> randomtestresults.out
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.c rngs.o interface.o $(CFLAGS)
	./randomtestadventurer >> randomtestresults.out
	gcov -b dominion.c >> randomtestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe randomtestcard1 randomtestcard1.exe randomtestcard2 randomtestcard2.exe randomtestadventurer randomtestadventurer.exe *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomtestresults.out
