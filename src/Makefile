all: mnemosyne

mnemosyne: main.o neural.o
	g++ main.o neural.o -o mnemosyne

main.o: main.cpp
	g++ -c main.cpp

neural.o: neural.cpp
	g++ -c neural.cpp

clean:
	rm *o mnemosyne



