output: main.o
	g++ -ggdb -Wall main.o -o output
main.o: source/main.cpp
	g++ -ggdb -Wall -c source/main.cpp
clean:
	rm *.o output
