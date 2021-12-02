CC=g++
CFLAGS=-Wall -g
RM=rm -f

day1: day1.o readlines.o
	$(CC) $(CFLAGS) -o day1_soln 1.o readlines.o

day1.o: day1/1.cpp day1/1.h helpers/readlines.cpp
	$(CC) $(CFLAGS) -c day1/1.cpp helpers/readlines.cpp

day2: day2.o readlines.o
	$(CC) $(CFLAGS) -o day2_soln 2.o readlines.o

day2.o: day2/2.cpp day2/2.h helpers/readlines.cpp
	$(CC) $(CFLAGS) -c day2/2.cpp helpers/readlines.cpp

readlines.o: helpers/readlines.h

clean:
	$(RM) *.o