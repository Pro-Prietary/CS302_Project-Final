output: main.o
	g++ -ggdb -Wall main.o -o output -std=c++11
main.o: source/main.cpp
	g++ -ggdb -Wall -c source/main.cpp -std=c++11
clean:
	rm *.o output
