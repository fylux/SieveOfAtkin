#include "Atkin.hpp"

//Comments Below

#define N_INV 16
#define N_FIRST_PRIMES 17


unsigned char inv[N_INV] = {1,7,11,13,17,19,23,29,31,37,41,43,47,49,53,59}; //invertible in Z60
unsigned char firstPrimes[N_FIRST_PRIMES] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59}; 


std::vector<bool> getPrimes(unsigned long int limit) {
	std::vector<bool> primes(limit); //*1
	unsigned long int n;
	bool isPrime = false;

	//First primes
	for (char i = 0; i < N_FIRST_PRIMES ; i++)
		primes[firstPrimes[i]] = true;
	
	for (unsigned long int w = 1; w <= ceil(limit/60)-1 ; w++) {
		for (char s = 0; s < N_INV ; s++) {
			n = 60 * w + inv[s];
			isPrime = false;

			unsigned long limitX;
			unsigned long limitY;

			//Algorithm 3.1
			if ( (inv[s] % 4 ) == 1 ) { //*2
				limitX = ceil(sqrt(n)/2);
				limitY = ceil(sqrt(n));
				for (unsigned long x = 1; x <= limitX; x++ ) //*3
					for (unsigned long y = 1; y <= limitY; y++ )
						if (4*x*x + y*y == n)
							isPrime = !isPrime;
			}
			//Algorithm 3.2
			else if ( (inv[s] % 6) == 1) { //*2
				limitX = ceil(sqrt(n)/3);
				limitY = ceil(sqrt(n));
				for (unsigned long x = 1; x <= limitX; x++ ) //*3
					for (unsigned long y = 1; y <= limitY; y++ )
						if (3*x*x + y*y == n)
							isPrime = !isPrime;
			}
			//Algorithm 3.3
			else if ( (inv[s] % 12 ) == 11) { //*2
				limitX = n;
				for (unsigned long x = 2; x <= limitX; x++ ) //*3
					for (unsigned long y = 1; y <= x-1; y++ )
						if (3*x*x - y*y == n)
							isPrime = !isPrime;
			}

			//Square Free
			for (int q = 2; q < sqrt(n) && isPrime ; q++) //*4
				if ( (primes[q] ) && ( n % (q*q) ==  0 ) )
					isPrime = false;
				
			if (isPrime)
				primes[n] = true;
		}
	}

	return primes;
}


//Comments
/**
 *1 : Using a bit vector is very space efficient but then you will have troubles finding where are the primes
 	which is necessary for finding squares (See *4). Other option is to use a set although you will need a lot 
 	space when working with big numbers which can't be stored in 4 bytes. Optimization should be done finding a
 	way to access to calculated primes in the bit vector.

 *2 : You can optimize this calculus by pre computing which invertible numbers meet each condition.

 *3 : This is a very inefficient way of finding solutions for the equations. The "paper" proposes interesting
 	method for finding solutions and there is a lot of research in this area, but I want to keep it simple.

 *4 : This way of finding the previously calculated primes and finding squares is not efficient and should
 	be optimized. First of all because you have to iterate the array to find which are the primes that you already
 	know, and secondly because probably there are better methods for findings squares.
 */