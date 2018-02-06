CXX= g++
CPPFLAGS= -g -Wall -pedantic-errors -O2 -std=gnu++11
CPPSOURCES= main.cpp chunk.cpp block.cpp player.cpp universe.cpp
CPPHEADERS= chunk.hpp block.hpp palayer.hpp universe.hpp double_vec.h
CPPOBJS= main.o chunk.o block.o player.o universe.o

default: all

main.o: main.cpp 
	${CXX} ${CPPFLAGS} -c main.cpp

block.o: block.cpp block.hpp
	${CXX} ${CPPFLAGS} -c block.cpp

chunk.o: chunk.cpp chunk.hpp
	${CXX} ${CPPFLAGS} -c chunk.cpp

player.o: player.cpp player.hpp
	${CXX} ${CPPFLAGS} -c player.cpp

universe.o: universe.cpp universe.hpp double_vec.hpp
	${CXX} ${CPPFLAGS} -c universe.cpp

all: ${CPPOBJS}
	${CXX} ${CPPFLAGS} ${CPPOBJS} -o Prog

test:
	${CXX} ${CPPFLAGS} test.cpp -lpthread
	

clean:
	rm -rf *.o Prog *.out *.gch
