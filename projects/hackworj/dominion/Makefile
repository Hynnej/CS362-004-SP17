CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

unitTest1: dominion.o unittest1.c rngs.o
	gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)	
	
unitTest2: dominion.o unittest2.c rngs.o
	gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
	
unitTest3: dominion.o unittest3.c rngs.o
	gcc -o unittest2 -g  unittest3.c dominion.o rngs.o $(CFLAGS)	
	
unitTest4: dominion.o unittest4.c rngs.o
	gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)		

cardTest1: dominion.o cardtest1.c rngs.o
	gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)	
	
cardTest2: dominion.o cardtest2.c rngs.o
	gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)	
	
unittestresults.out: cardtest1.c cardtest2.c cardtest3.c cardtest4.c unittest1.c unittest2.c unittest3.c unittest4.c dominion.c rngs.c

	echo "Result for running unit tests:" >  unittestresults.out
	
	echo "cardtest1.c:" >>  unittestresults.out
	gcc -o cardtest1 dominion.c rngs.c cardtest1.c $(CFLAGS)
	cardtest1 >>  unittestresults.out
	gcov -b -f dominion.c >>  unittestresults.out
	
	echo "cardtest2.c:" >>  unittestresults.out
	gcc -o cardtest2 dominion.c rngs.c cardtest2.c $(CFLAGS)
	cardtest2 >>  unittestresults.out
	gcov -b -f dominion.c >>  unittestresults.out	
	
	echo "cardtest3.c:" >>  unittestresults.out
	gcc -o cardtest3 dominion.c rngs.c cardtest3.c $(CFLAGS)
	cardtest3 >>  unittestresults.out
	gcov -b -f dominion.c >>  unittestresults.out
	
	echo "cardtest4.c:" >>  unittestresults.out
	gcc -o cardtest4 dominion.c rngs.c cardtest4.c $(CFLAGS)
	cardtest4 >>  unittestresults.out
	gcov -b -f dominion.c >>  unittestresults.out
	
	echo "unittest1.c:" >>  unittestresults.out
	gcc -o unittest1 dominion.c rngs.c unittest1.c $(CFLAGS)
	unittest1 >>  unittestresults.out
	gcov -b -f dominion.c >>  unittestresults.out
	
	echo "unittest2.c:" >>  unittestresults.out
	gcc -o unittest2 dominion.c rngs.c unittest2.c $(CFLAGS)
	unittest2 >>  unittestresults.out
	gcov -b -f dominion.c >>  unittestresults.out
	
	echo "unittest3.c:" >>  unittestresults.out
	gcc -o unittest3 dominion.c rngs.c unittest3.c $(CFLAGS)
	unittest3 >>  unittestresults.out
	gcov -b -f dominion.c >>  unittestresults.out
	
	echo "unittest4.c:" >>  unittestresults.out
	gcc -o unittest4 dominion.c rngs.c unittest4.c $(CFLAGS)
	unittest4 >>  unittestresults.out
	gcov -b -f dominion.c >>  unittestresults.out

all: rngs.o dominion.o unitTest2 unitTest1

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
