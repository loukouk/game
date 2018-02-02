CXX= g++
CPPFLAGS= -g -Wall -pedantic-errors -O2 -std=gnu++11
CPPSOURCES= main.cpp chunk.cpp block.cpp player.cpp universe.cpp
CPPHEADERS= chunk.h block.h palayer.h universe.h
CPPOBJS= main.o chunk.o block.o player.o universe.o

default: all

main.o: main.cpp
	${CXX} ${CPPFLAGS} -c main.cpp

block.o: block.cpp block.h
	${CXX} ${CPPFLAGS} -c block.cpp

chunk.o: chunk.cpp chunk.h
	${CXX} ${CPPFLAGS} -c chunk.cpp

player.o: player.cpp player.h
	${CXX} ${CPPFLAGS} -c player.cpp

universe.o: universe.cpp universe.h
	${CXX} ${CPPFLAGS} -c universe.cpp

all: ${CPPOBJS}
	${CXX} ${CPPFLAGS} ${CPPOBJS} -o Prog

clean:
	rm -rf *.o Prog *.out
