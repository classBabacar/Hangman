build: game

game: main.cc hangman.cc colors.h
	g++ -o game *.cc

clean:
	rm game