# CXX=g++-8
# CXX=clang++
CXXFLAGS=-O3 -std=c++17 -Wall -Wextra -Wpedantic

turing_blocks: Cell.o Cells.o Value.o State.o Step.o Action.o Goto.o Halt.o

clean:
	rm -f turing_blocks *.o
