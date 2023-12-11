all: main

main: main.cpp utils.cpp utils.hpp algorithms.hpp algorithms.tpp dropdown.hpp dropdown.cpp
	g++ -g -Wall -std=c++20 main.cpp utils.cpp dropdown.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

run: main
	./main

clean:
	rm main
