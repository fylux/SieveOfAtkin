#-D__NO_INLINE__ to avoid a Mingw bug

a.exe: main.o Atkin.o
	gcc -o a.exe main.o Atkin.o -lstdc++ -std=c++11 -O3 -D__NO_INLINE__ 

main.o : main.cpp Atkin.hpp
	gcc -c main.cpp -lstdc++ -std=c++11 -O3 -D__NO_INLINE__ 

Atkin.o : Atkin.cpp Atkin.hpp
	gcc -c Atkin.cpp -lstdc++ -std=c++11 -O3 -D__NO_INLINE__ 

run: a.exe
	a.exe