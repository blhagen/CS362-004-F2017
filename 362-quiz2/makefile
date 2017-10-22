#Brook Hagen
# CS362 Fall 2017
# Quiz 2
# Commands: make
#	    testme

CFLAGS = -Wall -std=c99 -lm -fpic -ftest-coverage -fprofile-arcs

testme: testme.o
	gcc testme.o -o testme $(CFLAGS)

clean:
	rm -f *.o testme.exe testme testme.gcov testme.gcda testme.gcno