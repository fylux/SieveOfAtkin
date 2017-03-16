#include <vector>
#include <iostream>
#include "Atkin.hpp"

using namespace std;

int main() {
	vector<bool> primes = getPrimes(1000);

	//List of primes below 1000
	for (int i = 0; i < 1000; i++)
		if (primes[i])
			cout << i << endl;

	return 0;
}