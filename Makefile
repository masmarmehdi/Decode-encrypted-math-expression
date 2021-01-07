.RACE01: all part_of_the_matrix uninstall clean reinstall

SRCS := $(wildcard src/*.c)

all: part_of_the_matrix

part_of_the_matrix:
	@clang -std=c11 -Wall -Wextra -Werror -Wpedantic ${SRCS} -o part_of_the_matrix

uninstall: clean
	@rm -f part_of_the_matrix

clean:
	@rm -f inc/*.gch

reinstall: uninstall part_of_the_matrix
