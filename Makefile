all: main

main: main.cpp
	g++ -g -Wall -std=c++20 main.cpp -o main

run: main
	./main

clean:
	rm main
