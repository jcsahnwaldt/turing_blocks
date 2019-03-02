# CC=gcc-8
# CC=clang
CFLAGS=-O3 -std=c11 -Wall -Wextra -Wpedantic -g

main: cell.o value.o state.o step.o action.o

run: main
	./main

valgrind: main
	valgrind --show-leak-kinds=all --leak-check=full --suppressions=valgrind.supp --gen-suppressions=all ./main

clean:
	rm -fr main *.o *.gch *.dSYM
