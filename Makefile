CXX= g++
CPPFLAGS= -g -Wall -Werror -pedantic-errors -O2
CPPSOURCES= main.cpp block.cpp
CPPHEADERS= block.h
CPPOBJS= main.o block.o

default: all

main.o: main.cpp
	${CXX} ${CPPFLAGS} -c main.cpp

block.o: block.cpp block.h
	${CXX} ${CPPFLAGS} -c block.cpp

all: block.o main.o
	${CXX} ${CPPFLAGS} ${CPPOBJS} -o Prog
