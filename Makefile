CC=g++
CFLAGS=-Wall -g
RM=rm -f

day1: day1.o readlines.o
	$(CC) $(CFLAGS) -o day1_soln 1.o readlines.o

day1.o: day1/1.cpp day1/1.h helpers/readlines.cpp
	$(CC) $(CFLAGS) -c day1/1.cpp helpers/readlines.cpp

readlines.o: helpers/readlines.h

clean:
	$(RM) *.o