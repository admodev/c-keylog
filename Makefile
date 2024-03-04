exec: clean compile bin/keylog src/main.o run

compile:
	echo "Starting compilation..."

bin/keylog: src/main.o
	echo "Linking"
	gcc -o bin/keylog $^

src/main.o: src/main.c
	echo "Compiling main.c"
	gcc -c src/main.c -o src/main.o -I./include -I./src

clean:
	test -e "bin/keylog" && rm bin/keylog || echo "The main file does not exist. Skipping clean..."

run:
	bin/keylog

all: compile run

