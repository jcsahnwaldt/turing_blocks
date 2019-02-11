CXX=g++-8
CXXFLAGS=-O3 -std=c++2a -Wall -Wextra -Wpedantic

# turing_blocks: Cell.cpp Step.cpp Transition.cpp State.cpp Value.cpp Action.cpp Halt.cpp
turing_blocks: Cell.o Step.o Transition.o State.o Value.o Action.o Halt.o

clean:
	-rm turing_blocks *.o
