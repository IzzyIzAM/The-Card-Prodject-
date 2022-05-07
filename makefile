card: board.o deck.o main.o player.o
	g++ board.o deck.o main.o player.o -o output

board.o: board.h board.cpp
	g++ -c board.h board.cpp

deck.o: deck.h deck.cpp
	g++ -c -w deck.h deck.cpp

main.o: main.cpp
	g++ -c main.cpp

player.o: player.h player.cpp
	g++ -c player.h player.cpp

run:
	make
	./output

clean:
	rm *.o *.h.gch output
