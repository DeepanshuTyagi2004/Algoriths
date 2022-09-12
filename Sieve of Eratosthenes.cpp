//Sieve of Eratosthenes
/*The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so
Let us take an example when n = 50. So we need to print all prime numbers smaller than or equal to 50. 

steps:-
1.We create a list of all numbers from 2 to 50.
2.According to the algorithm we will mark all the numbers which are divisible by 2 and are greater than or equal to the square of it.
3.Now we move to our next unmarked number 3 and mark all the numbers which are multiples of 3 and are greater than or equal to the square of it.
4.We move to our next unmarked number 5 and mark all multiples of 5 and are greater than or equal to the square of it.
5.We continue this process.
*/

// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n)
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++) {
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true) {
			// Update all multiples of p greater than or
			// equal to the square of it numbers which are
			// multiple of p and are less than p^2 are
			// already been marked.
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}

// Driver Code
int main()
{
	int n = 30;
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl;
	SieveOfEratosthenes(n);
	return 0;
}
/*
Time Complexity: O(n*log(log(n)))

Auxiliary Space: O(n)
*/