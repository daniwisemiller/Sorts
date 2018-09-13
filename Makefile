CFLAGS=-g -Wall -Werror -O2
CC=g++

all: project5

project5: main.cpp sort.o Makefile
	${CC} ${CFLAGS} -o project5 main.cpp sort.o

sort.o: sort.cc sort.h Makefile
	${CC} ${CFLAGS} -o sort.o -c sort.cc

clean:
	rm *.o project5


