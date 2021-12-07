CC=g++
CFLAGS=-Wall -g
RM=rm -f

day1: day1.o readlines.o
	$(CC) $(CFLAGS) -o day1_soln 1.o readlines.o

day1.o: day1/1.cpp day1/1.h helpers/readlines.cpp
	$(CC) $(CFLAGS) -c day1/1.cpp helpers/readlines.cpp

day2: day2.o readlines.o tokenise.o
	$(CC) $(CFLAGS) -o day2_soln 2.o readlines.o tokenise.o

day2.o: day2/2.cpp day2/2.h helpers/readlines.cpp helpers/tokenise.cpp
	$(CC) $(CFLAGS) -c day2/2.cpp helpers/readlines.cpp helpers/tokenise.cpp

day3: day3.o readlines.o
	$(CC) $(CFLAGS) -o day3_soln 3.o readlines.o

day3.o: day3/3.cpp day3/3.h helpers/readlines.cpp
	$(CC) $(CFLAGS) -c day3/3.cpp helpers/readlines.cpp

day4: day4.o readlines.o tokenise.o
	$(CC) $(CFLAGS) -o day4_soln 4.o readlines.o tokenise.o

day4.o: day4/4.cpp day4/4.h helpers/readlines.cpp helpers/tokenise.cpp
	$(CC) $(CFLAGS) -c day4/4.cpp helpers/readlines.cpp helpers/tokenise.cpp

day5: day5.o readlines.o tokenise.o
	$(CC) $(CFLAGS) -o day5_soln 5.o readlines.o tokenise.o

day5.o: day5/5.cpp day5/5.h helpers/readlines.cpp helpers/tokenise.cpp
	$(CC) $(CFLAGS) -c day5/5.cpp helpers/readlines.cpp helpers/tokenise.cpp

day6: day6.o readlines.o tokenise.o
	$(CC) $(CFLAGS) -o day6_soln 6.o readlines.o tokenise.o

day6.o: day6/6.cpp day6/6.h helpers/readlines.cpp helpers/tokenise.cpp
	$(CC) $(CFLAGS) -c day6/6.cpp helpers/readlines.cpp helpers/tokenise.cpp

readlines.o: helpers/readlines.h

tokenise.o: helpers/tokenise.h

clean:
	$(RM) *.o