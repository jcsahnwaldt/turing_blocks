# CXX=g++-8
# CXX=clang++
CXXFLAGS=-O3 -std=c++2a -Wall -Wextra -Wpedantic

# turing_blocks: Cell.cpp Step.cpp Action.cpp State.cpp Value.cpp Goto.cpp Halt.cpp
turing_blocks: Cell.o Step.o Action.o State.o Value.o Goto.o Halt.o

clean:
	rm -f turing_blocks *.o
