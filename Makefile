# CXX=g++-8
# CXX=clang++
CXXFLAGS=-O3 -std=c++2a -Wall -Wextra -Wpedantic

# turing_blocks: Cells.cpp Cell.cpp Value.cpp State.cpp Step.cpp Action.cpp Goto.cpp Halt.cpp
turing_blocks: Cells.o Cell.o Value.o State.o Step.o Action.o Goto.o Halt.o

clean:
	rm -f turing_blocks *.o
