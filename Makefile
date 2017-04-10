a.out : main.o Atkin.o
	g++ -o a.out main.o Atkin.o -std=c++11 -O2

main.o : main.cpp Atkin.hpp
	g++ -c main.cpp -std=c++11 -O2

Atkin.o : Atkin.cpp Atkin.hpp
	g++ -c Atkin.cpp -std=c++11 -O2

run : a.out
	./a.out
