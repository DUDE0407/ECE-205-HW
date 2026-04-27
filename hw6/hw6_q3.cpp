#include <iostream>
#include <vector>
using namespace std;

// Finds all prime numbers less than N using Sieve of Eratosthenes
vector<int> sieveOfEratosthenes(int N) {
    vector<bool> isPrime(N, true);

    isPrime[0] = false;
    if (N > 1) isPrime[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i < N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Main function to read N and print primes less than N
int main() {
    int N;
    cout << "Enter an integer N to find all primes less than N: ";
    cin >> N;

    if (N < 2) {
        cout << "No prime numbers less than " << N << ".\n";
        return 0;
    }

    vector<int> primes = sieveOfEratosthenes(N);

    cout << "Prime numbers less than " << N << ":\n";
    for (int i = 0; i < (int)primes.size(); i++) {
        cout << primes[i];
        if (i < (int)primes.size() - 1) cout << ", ";
    }
    cout << "\nTotal: " << primes.size() << " primes\n";

    return 0;
}
